#!/bin/bash
# set -x
#
# Copyright (c) 2015-2020 SUSE Linux AG, Nuernberg, Germany.
# All rights reserved.
#
# Authors:	Craig Salmond <csalmond@suse.com> 2015-2020
#
#     CPU Hot Plug Test
#


###############################################################################
###############################################################################
# Functions
###############################################################################
###############################################################################


#=============================================================================#
#
function Usage()
{
    >&2 echo "
Usage:   $0 [-d dir_name] [-h] [-i IP_address] [-p Log_prefix]

Options:
	-h	Print this help text and exit.
	-d	Name of project directory (for logging).
	-i	IP address of SUT.
	-p	Add prefix string to log file name.
"
}


#=============================================================================#
#
function MyExit()
{
	local let status=$1

	mkdir -p ${DEFAULT_LOGDIR}/testwrapper
	echo "${status}" > ${DEFAULT_LOGDIR}/testwrapper/${Prefix}_status
	if [ ${status} -eq ${PASS} ] ; then
		timed_log "Test Finished normally - Passed" >> ${LOG}
	elif [ ${status} -eq ${FAIL} ] ; then
		timed_log "Test Finished normally - Failed" >> ${LOG}
	elif [ ${status} -eq ${PASS_W_WARNING} ] ; then
		timed_log "Test Finished normally - Passed w/warning" >> ${LOG}
	elif [ ${status} -eq ${NOT_SUPPORTED} ] ; then
		timed_log "Test Finished normally - Not Supported" >> ${LOG}
	elif [ ${status} -eq ${NOT_APPLICABLE} ] ; then
		timed_log "Test Finished normally - Not Applicable" >> ${LOG}
	else
		timed_log "Test Finished normally - Unknown status" >> ${LOG}
	fi
	exit ${status}
}


#=============================================================================#
# Validates that the CPU will go offline (from an online state)
#
function DoOfflineTest()
{
	local tmp=""
	local size=0
	local retry=5

	${STAT} --format=%s /var/log/messages
	BeforeFileSize=${results}
	echo "Testing if CPU ${1} will go offline..." >> ${LOG}
	echo 0 > ${BaseDir}/cpu${1}/online
	while [ ${retry} -gt 0 ] ; do
		${SLEEP} 1
		${STAT} --format=%s /var/log/messages
		AfterFileSize=${results}
		size=$(( AfterFileSize - BeforeFileSize ))
		# Check/log /var/log/messages to see how the operation went
		 ${IpAddr} \
			"${TAIL} -c ${size} /var/log/messages | ${GREP} \"CPU ${1} is now offline\"
		if [ "${results}" != "" ] ; then
			echo "CPU ${1} is now offline." >> ${LOG}
			break
		fi
		${CAT} ${BaseDir}/cpu${1}/online
		if [ $? -eq 0 -a ${results} -eq 0 ] ; then
			echo "CPU ${1} is now offline." >> ${LOG}
			break
		fi
		retry=$(( retry -1 ))
	done
	if [ ${retry} -le 0 ] ; then
		echo -e "\n***\n" >> ${LOG}
		echo "Error: CPU ${1} did not go offline" >> ${LOG}
		echo -e "\n***\n" >> ${LOG}
		let ErrorCount=${ErrorCount}+1
	else
		echo -e "Pass\n\n" >> ${LOG}
	fi
}


#=============================================================================#
# Validates that the CPU will go online (from an offline state)
#
function DoOnlineTest()
{
	local tmp=""
	local size=0
	local retry=5

	${STAT} --format=%s /var/log/messages
	BeforeFileSize=${results}
	echo "Testing if CPU ${1} will go online..." >> ${LOG}
	echo 1 > ${BaseDir}/cpu${1}/online
	while [ ${retry} -gt 0 ] ; do
		${SLEEP} 1
		${STAT} --format=%s /var/log/messages
		AfterFileSize=${results}
		# Check/log /var/log/messages to see how the operation went
		size=$(( AfterFileSize - BeforeFileSize ))
		 ${IpAddr} \
			"${TAIL} -c  ${size} /var/log/messages | ${GREP} \"Booting Node [0-9]* Processor ${1} \"
		if [ "${results}" = "" ] ; then
			echo "CPU ${1} is now online." >> ${LOG}
			break
		fi
		${CAT} ${BaseDir}/cpu${1}/online
		if [ $? -eq 0 -a ${results} -eq 1 ] ; then
			echo "CPU ${1} is now online." >> ${LOG}
			break
		fi
		retry=$(( retry -1 ))
	done
	if [ ${retry} -le 0 ] ; then
		echo -e "\n***\n" >> ${LOG}
		echo "Error: CPU ${1} did not go online" | ${TEE} -a ${LOG}
		echo -e "\n***\n" >> ${LOG}
		let ErrorCount=${ErrorCount}+1
	else
		echo -e "Pass\n\n" >> ${LOG}
	fi
}


#=============================================================================#
#
function VerifyOnlineCpus()
{
	local cpuOffline=$1
	local cntMinus=0
	local cntPlus=0
	local cpusOnline=0

	# Check to see what CPUs are online
	${CAT} ${BaseDir}/online
	cpusOnline=${results}
	if [ "${cpuOffline}" = "" ] ; then
		if [ "${cpusOnline}" != "0-${Count}" ] ; then
			echo -e "\n***\n" >> ${LOG}
			echo "Error: CPUs Online = ${cpusOnline}, should be:" \
				"0-${Count}." >> ${LOG}
			echo -e "\n***\n" >> ${LOG}
			let ErrorCount=${ErrorCount}+1
		fi
	else
		if [ ${cpuOffline} -eq 0 ] ; then
			if [ "${cpusOnline}" != "1-${Count}" ] ; then
				echo -e "\n***\n" >> ${LOG}
				echo "Error: CPUs Online = ${cpusOnline}, should be:" \
					"1-${Count}." >> ${LOG}
				echo -e "\n***\n" >> ${LOG}
				let ErrorCount=${ErrorCount}+1
			fi
		elif [ ${cpuOffline} -eq 1 ] ; then
			if [ ${Count} -eq 1 ] ; then
				if [ "${cpusOnline}" != "0" ] ; then
					echo -e "\n***\n" >> ${LOG}
					echo "Error: CPUs Online = ${cpusOnline}, should be: 0" \
						>> ${LOG}
					echo -e "\n***\n" >> ${LOG}
					let ErrorCount=${ErrorCount}+1
				fi
			elif [ ${Count} -eq 2 ] ; then
				if [ "${cpusOnline}" != "0,2" ] ; then
					echo -e "\n***\n" >> ${LOG}
					echo "Error: CPUs Online = ${cpusOnline}, should be:" \
						"0,2" >> ${LOG}
					echo -e "\n***\n" >> ${LOG}
					let ErrorCount=${ErrorCount}+1
				fi
			else
				if [ "${cpusOnline}" != "0,2-${Count}" ] ; then
					echo -e "\n***\n" >> ${LOG}
					echo "Error: CPUs Online = ${cpusOnline}, should be:" \
						"0,2-${Count}." >> ${LOG}
					echo -e "\n***\n" >> ${LOG}
					let ErrorCount=${ErrorCount}+1
				fi
			fi
		elif [ ${cpuOffline} -eq ${Count} ] ; then
			cntMinus=$(( Count -1 ))
			if [ "${cpusOnline}" != "0-${cntMinus}" ] ; then
				echo -e "\n***\n" >> ${LOG}
				echo "Error: CPUs Online = ${cpusOnline}, should be:" \
					"0-${cntMinus}." >> ${LOG}
				echo -e "\n***\n" >> ${LOG}
				let ErrorCount=${ErrorCount}+1
			fi
		elif [ ${cpuOffline} -eq $(( Count -1 )) ] ; then
			cntMinus=$(( Count -2 ))
			if [ "${cpusOnline}" != "0-${cntMinus},${Count}" ] ; then
				echo -e "\n***\n" >> ${LOG}
				echo "Error: CPUs Online = ${cpusOnline}, should be:" \
					"0-${cnt},${Count}." >> ${LOG}
				echo -e "\n***\n" >> ${LOG}
				let ErrorCount=${ErrorCount}+1
			fi
		else
			let cntMinus=${cpuOffline}-1
			let cntPlus=${cpuOffline}+1
			if [ "${cpusOnline}" != "0-${cntMinus},${cntPlus}-${Count}" ]
			then
				echo -e "\n***\n" >> ${LOG}
				echo "Error: CPUs Online = ${cpusOnline}, should be:" \
					"0-${cntMinus},${cntPlus}-${Count}." >> ${LOG}
				echo -e "\n***\n" >> ${LOG}
				let ErrorCount=${ErrorCount}+1
			fi
		fi
	fi
}


#=============================================================================#
# cat contents of each file in the given list in this format:
# paths = Paths to cat file in.
# contents_of_file...
#
function CatRemoteFiles()
{
	local path=$1
	local recursive=$2
	local files=""
	local file=""
	local fileType=""

	${LS} -l ${path}
	files=$( echo "${results}" | ${TR} -s ' ' | ${SED} 's/ /%/g' )
	for file in ${files} ; do
		fileType=$( echo "${file}" | ${CUT} -c 1 )
		fileName=$( echo "${file}" | ${CUT} -d '%' -f 9 )
		if [ "${fileType}" = "d" -a "${recursive}" != "" ] ; then
			# make a recursive call
			CatRemoteFiles ${path}/${fileName}
		fi
		if [ "${fileType}" = "-" ] ; then
			${CAT} ${path}/${fileName} 2>&1
			echo "" >> ${LOG}
		fi
	done
}



###############################################################################
###############################################################################
# Main line code
###############################################################################
###############################################################################


#=============================================================================#
# Evaluate and check the command line
#
ProjectDir=""
IpAddr=""
Prefix="cpuHotPlug"

while getopts d:hi:p: optchar ; do
	case "${optchar}" in
		h)	Usage
			exit 1					;;
		d)	ProjectDir=${OPTARG}	;; # normally gets this from testwrapper
		i)	IpAddr=${OPTARG}		;;
		p)	Prefix=${OPTARG}		;;
		*)	Usage
			exit 1					;; 
	esac
done
shift $((OPTIND - 1))

echo "1" > /var/opt/suse/testKits/system/${ProjectDir}/testwrapper/${Prefix}_status


#=============================================================================#
# Script-Global variables
#
Timestamp=$(date "+%Y%m%d.%H%M%S")
Basename=${Prefix}-${Timestamp}
BaseDir="/sys/devices/system/cpu"
ErrorCount=0
WarnCount=0
Data=""
Count=0


#=============================================================================#
# Used library
#
lib_found=""
libdirs="/opt/suse/testKits/system/lib"

for dir in ${libdirs} ; do
    if [ -x ${dir}/cert_tests.lib ] ; then
          . ${dir}/cert_tests.lib
          lib_found="yes"
          break  # found ; one time is enough
    fi
done
if [ -z "${lib_found}" ] ; then
    >&2 echo -e "\a$0: Needed cert_tests.lib not found in: ${libdirs}. Aborting..."
    exit 1 
fi
unset lib_found libdirs

#=============================================================================#
# Commands used
# (see also: cert_tests.lib)
# Everything we need available?
#
LOG=${DEFAULT_LOGDIR}/misc/${Basename}.log

if [ ! -d "${DEFAULT_LOGDIR}/misc/" ] ; then
	${MKDIR} -p "${DEFAULT_LOGDIR}/misc/"
fi

timed_log "CPU Hot Plug Test log started." >> ${LOG}

NUMACTL=/usr/bin/numactl	# does not exist on SLE 11 i586

NEEDED_REMOTE_CMDS="${CAT} ${NUMACTL} ${STAT} ${TAIL}"

NEEDED_CMDS="${CAT} ${CUT} ${DATE} ${GREP} ${HWINFO} ${MKDIR} ${SED} ${STAT} ${TAIL} ${TAR} ${TEE} ${TR}"

check_for_needed_cmds ${NEEDED_CMDS} || MyExit ${FAIL}

insureSshWorks ${IpAddr}
if [ $? -ne 0 ] ; then
	MyExit ${FAIL}
fi
#if [ ${RemoteOsVerNum} -lt 123 ] ; then
#	echo -e "\n***\n" >> ${LOG}
#	echo "This test is not applicable prior to SLE 12 SP3." >> ${LOG}
#	echo -e "\n***\n" >> ${LOG}
#	MyExit ${NOT_APPLICABLE}
#fi

uname -i | ${SED} s/i.86/i586/
Arch=${results}
echo "${IpAddr}: Arch=\"${Arch}\"" >> ${LOG}

if [ "${Arch}" = "s390x" -a "${RemoteOsVerNum}" -lt 150 ] ; then    
    echo -e "\n***\n" >> ${LOG}
    echo "This test is not applicable to s390x prior to SLE 15 GA." \
        >> ${LOG}
    echo -e "\n***\n" >> ${LOG}
    MyExit ${NOT_APPLICABLE}
fi

checkForNeededRemoteCmds ${IpAddr} ${NEEDED_REMOTE_CMDS} || MyExit ${FAIL}

#=============================================================================#
# Now DO IT
#

# Note: Some times the CPU has cores that are disabled (not present).
# Disabled CPUs show up as offline in ${BaseDir}/offline.
CatRemoteFiles ${BaseDir}

# This test really doesn't apply if there is only one CPU Socket.
${LSCPU}
Data=$( echo "${results}" | ${GREP} "^Socket(s)" | ${CUT} -d ':' -f 2 \
	| ${TR} -d ' ' )
if [ ${Data} -eq 1 ] ; then
	echo -e "\n***\n" >> ${LOG}
	echo "This test only applies to machines with more than one CPU Socket." >> ${LOG}
	echo -e "\n***\n" >> ${LOG}
	MyExit ${NOT_APPLICABLE}
fi

# Count all online and offline CPU (except s390x arch just count online cpus).
DoesFileExistOnSut ${IpAddr} /${BaseDir}/online
if [ $? -eq 1 -a "${Arch}" != "s390x" ] ; then
	 ${IpAddr} \
		"${CAT} /${BaseDir}/online | ${SED} 's/-/ /g' | ${SED} 's/,/ /g'"
	for indx in ${results} ; do
		if [ ${indx} -gt ${Count} ] ; then
			Count=${indx}
		fi
	done
else
	${LSCPU}
	let Count=$( echo "${results}" | ${GREP} "^CPU(s):" | ${CUT} -d ':' -f 2 | ${TR} -d ' ' )
	echo "CPU count=${Count}" >> ${LOG}
	# Make Count zero based
	Count=$(( Count -1 ))
fi
echo "CPU count=${Count}" >> ${LOG}

# If there are any CPUs off line, make sure all go online.
Data=$( echo "${results}" | ${GREP} "Off-line CPU(s) List:" )
if [ "${Data}" != "" ] ; then
	# Make sure all CPUs will go on-line.
	for (( indx=0; indx <= ${Count} ; indx++ )) ; do
		echo 1 > ${BaseDir}/cpu${1}/online
	done
	${SLEEP} 1
	${LSCPU}
	Data=$( echo "${results}" | ${GREP} "Off-line CPU(s) List:" )
	if [ "${Data}" != "" ] ; then
		echo -e "\n***\n" >> ${LOG}
		echo "Error: Unable to online all CPUs." >> ${LOG}
		echo -e "\n***\n" >> ${LOG}
		ErrorCount=$(( ErrorCount +1 ))
	fi
fi

echo "${NUMACTL} -H:" >> ${LOG}
${NUMACTL} -H

# Test each CPU individually to make sure each goes off and back online.
for (( indx=0; indx <= ${Count} ; indx++ )) ; do
	echo -e "\n\nTesting CPU${indx}:" >> ${LOG}
	DoesFileExistOnSut ${IpAddr} "${BaseDir}/cpu${indx}/online"
	if [ $? -eq 1 ] ; then
		DoOfflineTest ${indx}
		VerifyOnlineCpus ${indx}
		DoOnlineTest ${indx}
		VerifyOnlineCpus
	else
		if [ ${indx} -eq 0 ] ; then
			echo "Notice: ${BaseDir}/cpu${indx}/online does not exist." >> ${LOG}
			CatRemoteFiles ${BaseDir}/cpu${indx}
		else
			echo -e "\n***\n" >> ${LOG}
			echo "Error: ${BaseDir}/cpu${indx}/online does not exist." >> ${LOG}
			echo -e "\n***\n" >> ${LOG}
			CatRemoteFiles ${BaseDir}/cpu${indx}
			ErrorCount=$(( ErrorCount +1 ))
		fi
	fi
done

# TODO: Create a test to take each node/Socket offline and back online.

echo "ErrorCount=${ErrorCount}" >> ${LOG}
if [ ${ErrorCount} -ge 1 ] ; then
	MyExit ${FAIL}
elif [ ${WarnCount} -ge 1 ] ; then
	MyExit ${PASS_W_WARNING}
else
	MyExit ${PASS}
fi
