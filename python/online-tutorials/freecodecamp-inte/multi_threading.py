#!/usr/bin/env python3
# Multi-Threading
from threading import Thread
import os
import time

def square_numbers():
    for i in range(100):
        i * i
        time.sleep(0.1)

my_threads = []
num_threads = 10

#create threads
for i in range(num_threads):
    t = Thread(target=square_numbers)
    my_threads.append(t)

# start each thread
for t in my_threads:
    t.start()

# join
for t in my_threads:
    t.join() #waitin for all threads to finish, locks the main thread

print('end main')