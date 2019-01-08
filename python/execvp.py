#python test
import os
# logstr(conf,"here cmdline[0] %s --end" % cmdline[0])
#			logstr(conf,"cmdargs: %s --end" % cmdargs)
#			os.execvp(cmdline[0], [ cmdline[0], ]+cmdargs)
#	logstr(conf, time.ctime())
#	pid = os.fork()
#	if pid == 0: # child
		WaitForPID = pid
		# clear signal handlers
		try:
			signal.signal(signal.SIGALRM, signal.SIG_IGN)
			os.setsid()
			os.dup2(f.fileno(),sys.stdout.fileno())
			os.dup2(f.fileno(),sys.stderr.fileno())
            cmdline=['/usr/bin/gnome-terminal']
            cmdargs=['-x', '/bin/bash -c', '/home/InstSource/sck/sck_copy_install_files.sh -i 192.168.100.30']
			executed=[]
			executed.append("Executed ")
			os.execvp(cmdline[0], [ cmdline[0], ]+cmdargs)

		except Exception,e:
			sys.exit(1)



#os.execvp('/usr/bin/uname', ['/usr/bin/uname', '-a'])
