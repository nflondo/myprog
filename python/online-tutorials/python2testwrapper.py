import os,glob
import sys,time
import signal
import re
import string
import commands

try:
		os.stat( "/etc/SuSE-release" )
		with open( "/etc/SuSE-release" ) as f:
			for line in f:
				if re.search("VERSION =", line) != None:
					ver = string.split( line, " " )
					osVer = ver[2]
				if re.search("PATCHLEVEL =", line) != None:
					sp = string.split( line )
					osVer = ver[2] + "." + sp[2]
except OSError:
	with open( "/etc/os-release" ) as f:
		for line in f:
			if re.search("VERSION=", line) != None:
				ver = string.split( line, '"' )
				osVer = ver[1]
                print(osVer)
finally:
	f.close()		