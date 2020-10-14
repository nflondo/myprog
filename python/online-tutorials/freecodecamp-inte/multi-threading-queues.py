#!/usr/bin/env python3
# Multi-Threading
# Queues. Linear data structure follows FIFO e.g customers waiting in line
from threading import Thread, Lock, current_thread
from queue import Queue
import time

def worker(q, lock):
    while True:
        value = q.get() # infinite loop is thread safe.  Starts with nothing
        # so it locks
        # processing...
        with lock:
            print(f'in {current_thread().name} got {value}')
        q.task_done()

if __name__ == "__main__":

    q = Queue ()
    lock = Lock()
    num_threads = 10

    for i in range(num_threads):
        thread = Thread(target=worker, args=(q, lock))
        thread.daemon=True #background thread that dies when main thread dies
                        #needed to end properly while loop in worker() above
        thread.start()

    for i in range(1, 21):
        q.put(i) # thread safe
                # put items in the queue

    q.join()
'''
    q.put(1)
    q.put(2)
    q.put(3)

    # 3 2 1 ---->
    first = q.get()
    print(first) #prints 1

    #q.empty() # will empty queue
    q.task_done() # tells program we're done processing with this object
    q.join() # waits until all elements in queue are processed
'''
    #print('end main')