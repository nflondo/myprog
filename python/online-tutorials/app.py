# app.py
import os,glob
import sys,time
import signal
import re
import string
import commands

program = 'python'
arguments = ['mod2.sh']
studentlist = ['one','two','three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen']
#print(os.execvp(program, (program,) + tuple(arguments)))
print("Executed: "+program + " " + " ".join(arguments))
#print(os.execvp(program, [program,] + arguments))
#print(os.execvp(program, [program,] + studentlist))

#cmdline=['python']
#cmdargs = ['myarg1','myarg2','myarg3']
#print(os.execvp(cmdline[0], [ cmdline[0], ]+cmdargs))
