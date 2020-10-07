#!/usr/bin/env python3
# multi-processing
from multiprocessing import Process
import os
import time

def square_numbers():
    for i in range(100):
        i * i
        time.sleep(0.1)

my_processes = []
num_processes = os.cpu_count() #gets number of cpus in machine

#create processes
for i in range(num_processes):
    p = Process(target=square_numbers)
    my_processes.append(p)

# start each process
for p in my_processes:
    p.start()

# join
for p in my_processes:
    p.join() #waitin for all processes to finish, locks the main thread

print('end main')
