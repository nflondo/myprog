#!/usr/bin/env python3
# multi-processing
# Different processes live in different memory spaces, they don't share data
# Need special share memory objects to share data such as Value and Array
from multiprocessing import Pool

def cube(number):
    return number * number * number

# When script is being run directly __name__ = __main__ if it's being imported
#and run indirectly, the __name__ variable is set to the other script
# https://www.geeksforgeeks.org/what-does-the-if-__name__-__main__-do/
if __name__ == "__main__": 

    numbers = range(10)
    pool = Pool()
    # important methods: map, apply, join, close
    # create multiple process that should execute a function
    # Will automatically allocate the maximum number of processes available
    # then will split iterable into equal size chunks and submit to function
    result = pool.map(cube, numbers)

    #pool.apply(cube, numbers[0])#executes with one argument

    pool.close()
    pool.join()

    print(result)
