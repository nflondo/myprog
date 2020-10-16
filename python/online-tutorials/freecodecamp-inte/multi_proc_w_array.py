#!/usr/bin/env python3
# multi-processing
# Different processes live in different memory spaces, they don't share data
# Need special share memory objects to share data such as Value and Array
from multiprocessing import Process, Value, Array, Lock
import time

def add_100(numbers, lock):
    #for i in range(len(numbers)):
    for i in range(100):
        time.sleep(0.01)
        for i in range(len(numbers)):
            with lock:
                numbers[i] += 1
 

# When script is being run directly __name__ = __main__ if it's being imported
#and run indirectly, the __name__ variable is set to the other script
# https://www.geeksforgeeks.org/what-does-the-if-__name__-__main__-do/
if __name__ == "__main__": 

    lock = Lock()
    shared_array = Array('d', [0.0, 100.0, 200.0]) #'d' = double
    print('Array at beginning is', shared_array[:])

    p1 = Process(target=add_100, args=(shared_array, lock))
    p2 = Process(target=add_100, args=(shared_array, lock))

    p1.start()
    p2.start()

    p1.join()
    p2.join()

    print('Array at end is', shared_array[:])