#!/usr/bin/env python3
# Use this class as context manager
class ManagedFile:
    def __init__(self, filename):
        print('init')
        self.filename = filename

    def __enter__(self):
        print('enter')
        self.file = open(self.filename, 'w')
        return self.file

    def __exit__(self, exc_type, exc_value, exc_traceback):
        if self.file:
            self.file.close()
        if exc_type is not None:
            print('exception has been handled')
        #print('exc:', exc_type, exc_value)
        print('exit')
        return True

with ManagedFile('notes.txt') as f:
    print('do some stuff')
    f.write('some to do')
    f.somemethod() # even if there is an exception, class can still close file
print('continuing')


