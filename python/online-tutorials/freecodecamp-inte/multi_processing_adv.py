#!/usr/bin/env python3
# multi-processing
# Different processes live in different memory spaces, they don't share data
# Need special share memory objects to share data such as Value and Array
from multiprocessing import Process, Value, Array, Lock
import os
import time

def add_100(number, lock):
    for i in range(100):
        #lock.acquire()
        time.sleep(0.01)
        with lock: #context manager: this automatically acquires and releases the lock
            number.value += 1
        #lock.release()

# When script is being run directly __name__ = __main__ if it's being imported
#and run indirectly, the __name__ variable is set to the other script
# https://www.geeksforgeeks.org/what-does-the-if-__name__-__main__-do/
if __name__ == "__main__": 

    lock = Lock()
    shared_number = Value('i', 0)
    print('Number at beginning is', shared_number.value)

    p1 = Process(target=add_100, args=(shared_number, lock))
    p2 = Process(target=add_100, args=(shared_number, lock))

    p1.start()
    p2.start()

    p1.join()
    p2.join()

    print('number at end is', shared_number.value)