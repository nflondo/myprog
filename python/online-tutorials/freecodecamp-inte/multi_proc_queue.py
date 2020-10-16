#!/usr/bin/env python3
# multi-processing
# Different processes live in different memory spaces, they don't share data
# Need special share memory objects to share data such as Value and Array
from multiprocessing import Process, Value, Array, Lock
from multiprocessing import Queue #linear data FIFO
import time

def square(numbers, queue):
    for i in numbers:
        queue.put(i*i)

def make_negative(numbers, queue):
    for i in numbers:
        queue.put(-1*i)
 

# When script is being run directly __name__ = __main__ if it's being imported
#and run indirectly, the __name__ variable is set to the other script
# https://www.geeksforgeeks.org/what-does-the-if-__name__-__main__-do/
if __name__ == "__main__": 
    numbers = range(1, 6)
    q = Queue()
    p1 = Process(target=square, args=(numbers, q))
    p2 = Process(target=make_negative, args=(numbers, q))

    p1.start()
    p2.start()

    p1.join()
    p2.join()

    while not q.empty():
        print(q.get()) #remove and return first element in queue