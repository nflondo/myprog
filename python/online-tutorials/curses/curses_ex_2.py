#!/usr/bin/env python3
#Title: Curses Programming Example
# Plot some math functions
# Controls:
#       Left/Right arrows, adjust k parameter
#       Up/Down arrows, adjust amplitude
#       s: sine
#       c: cosine
#       t: tangent
#       h: make it hyperbolic
#       q: quit the program
# Author: Jack Rosenthal

# We need to import curses to use it
import curses

# I am also going to be using the math library in this example
import math

# The easiest way to use curses is to use a wrapper around a main function
# Essentially, what goes in the main function is the body of your program,
# The `stdscr' parameter passed to it is the curses screen generated by our
# wrapper.
def main(stdscr):
    # In this program, we don't want keystrokes echoed to the console,
    # so we run this to disable that
    curses.noecho()

    # Additionally, we want to make it so that the user does not have to press
    # enter to send keys to our program, so here is how we get keys instantly
    curses.cbreak()

    # Hide the cursor
    curses.curs_set(0)

    # Lastly, keys such as the arrow keys are sent as funny escape sequences to
    # our program. We can make curses give us nicer values (such as curses.KEY_LEFT)
    # so it is easier on us.
    stdscr.keypad(True)

    # The value in the division of the x coord
    k = 12

    # The amplitude of the sine wave to draw
    a = 0

    # The math function to plot, initially sin
    mathfunc = math.sin

    # Here is the loop of our program, we keep clearing and redrawing in this loop
    while True:
        # First, clear the screen
        stdscr.erase()

        # Next, let's generate a list of points to draw for our screen size
        max_y, max_x = stdscr.getmaxyx()
        points = []
        for point_x in range(max_x):
            points.append((int(a*mathfunc(point_x/(k+0.001))) + max_y//2, point_x))

        # Next, let's draw the wave using the .addstr(y, x, str) method on screens
        for point in points:
            try:
                stdscr.addstr(point[0], point[1], "*")
            except:
                pass

        # Draw the screen
        stdscr.refresh()

        # Wait for a keystroke
        key = stdscr.getch()

        # Process the keystroke
        if key == curses.KEY_LEFT:
            k = k - 1
        elif key == curses.KEY_RIGHT:
            k = k + 1
        elif key == curses.KEY_UP and a < (max_y // 2):
            a = a + 1
        elif key == curses.KEY_DOWN and a > -(max_y // 2):
            a = a - 1
        elif key == ord('s'):
            mathfunc = math.sin
        elif key == ord('c'):
            mathfunc = math.cos
        elif key == ord('t'):
            mathfunc = math.tan
        elif key == ord('h'):
            mathfunc = getattr(math, mathfunc.__name__ + 'h')
        elif key == ord('q'):
            break

# Call the wrapper on our main function:
curses.wrapper(main)
