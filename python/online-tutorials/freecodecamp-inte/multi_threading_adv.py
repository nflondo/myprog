#!/usr/bin/env python3
# Multi-Threading
# How to share data.
from threading import Thread, Lock
import os
import time

database_value = 0

def increase(lock):
    global database_value
    # using with context manager don't to manually lock and release
    with lock:
        local_copy = database_value
        local_copy = database_value
        # processing
        local_copy +=1
        time.sleep(0.1)
        database_value = local_copy
'''
    lock.acquire()
    local_copy = database_value
    # processing
    local_copy +=1
    time.sleep(0.1)
    database_value = local_copy
    lock.release() #always release a lock or you'll get stuck
'''
if __name__ == "__main__":
    print('start value', database_value)

    lock = Lock()

    thread1 = Thread(target=increase, args=(lock,))
    thread2 = Thread(target=increase, args=(lock,))

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

    print('end value', database_value)

    print('end main')