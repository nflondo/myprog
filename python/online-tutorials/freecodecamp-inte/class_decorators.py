#!/usr/bin/env python3
# For maintaining states

class CountCalls:

    def __init__(self, func):
        self.func = func
        self.num_calls = 0

    def __call__(self, *args, **kwargs):
        #print('Hi there')
        self.num_calls += 1
        print(f'This is executed {self.num_calls} times')
        return self.func(*args, **kwargs)


#cc = CountCalls(None)
#cc()

@CountCalls # class decorators.
def say_hello():
    print('Hello')

say_hello()
say_hello()