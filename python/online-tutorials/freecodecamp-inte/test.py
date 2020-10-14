#!/usr/bin/env python3
import time

curtime = time.localtime()
#print(curtime)
#print("%d-%02d-%02d %02d:%02d:%02d" % curtime[0:6])

test_results = {'mem':{'name':'memory', 'status':3, 'time':'4:00pm'}}
print(test_results['mem']['name'])