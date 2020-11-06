#!/usr/bin/env python3
# Context Managers provide resource management. Allow to allocate and release resources
with open('notes.txt', 'w') as f: # context mgr correctly closes the file
    f.write('some to do....')

# Without a context mgr, you have to do it this way:
myfile = open('notes.txt', 'w')
try:
    myfile.write('some text in the file')
finally:
    myfile.close()

#open and close db connections

# lock
from threading import Lock
lock = Lock()
lock.acquire()
#...
lock.release() # if forget to close, then run into a deadlock

# using context
# with lock: #automatically acquire the lock, the releases it when leaves with


