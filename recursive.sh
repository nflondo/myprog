#==============================================================================
# 
function makeRecursive()
{
	#currentDir needs to be a full path ending with a "/"	
	local dirList
	currentDir=$1
	echo "currentDir=${currentDir}" >> ${LOG}
	echo "cd ${currentDir}" >> ${LOG}
	cd ${currentDir} >> ${LOG} 2>&1
	dirList=$(/usr/bin/ls -d */ >> ${LOG} 2>&1)
	echo "dirList=${dirList}" >> ${LOG}

	for dir in ${dirList};do
		echo "makeRecursive ${dir}" >> ${LOG}
		makeRecursive ${dir}
	done
#	make >> ${LOG} 2>&1
	echo "Running cmd: /usr/bin/touch fakefile" >> ${LOG}
	/usr/bin/touch fakefile >> ${LOG} 2>&1
	echo "cd .." >> ${LOG}
	cd ..
	echo "pwd: `pwd`" >> ${LOG}
}

LOG=/tmp/makerecursivelog.txt
PATH=/home/myprog/

makeRecursive ${PATH}
