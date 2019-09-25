###############################################################################
###############################################################################
# Main line code
###############################################################################
###############################################################################
# Start up Variables
ProjectDir=""
ErrorCheckCode=1 # start with fail status
#SutIpAddr=""
Prefix="tempest_run"
RunTime=0
AdminIp=""
Control1Ip=""
Control2Ip=""
Control3Ip=""
ComputeIp=""
Failed=0

while getopts hd:p:r:v:w:x:y:z: optchar ; do
	case "${optchar}" in
		h)	usage
			exit 1					;;
		d) 	ProjectDir=${OPTARG}	;;
		p)	Prefix=${OPTARG}		;;
		r) 	RunTime=${OPTARG}		;;
        v)  AdminIp=${OPTARG}       ;;
		w)	Control1Ip=${OPTARG}	;;
		x)	Control2Ip=${OPTARG}	;;
		y)	Control3Ip=${OPTARG}	;;
		z)	ComputeIp=${OPTARG}	;;
		*)	usage
			exit 1					;;
	esac
done
shift $((OPTIND - 1))

echo "ProjectDir=${ProjectDir}, Prefix=${Prefix}, RunTime=${RunTime}, AdminIp=${AdminIp}

	Control1Ip=${Control1Ip}, Control2Ip=${Control2Ip}, Control3Ip=${Control3Ip} ComputeIp={ComputeIp}"
