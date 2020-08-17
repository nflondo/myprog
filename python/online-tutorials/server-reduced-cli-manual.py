#!/usr/bin/env python3
import sys,os
import curses, subprocess
import cmd_library
'''
def execute_cmd(cmd_string):
    subprocess.call('clear')
    ret = subprocess.call(cmd_string)
    print ("")
    if ret == 0:
        print ("Command executed successfully! :-)")
    else:
        print ("Command terminated with status other than zero :-(")
    input("Press enter")
    print ("")    
'''
sutIpAddress = cmd_library.get_tsf_data() 
if not sutIpAddress: # no tsf file found
    sutIpAddress = cmd_library.get_sut_ip_address() # get info directly from user

# Loop where k is the last character pressed
# ord() returns the unicode code point for a one-character string #
k = 0
while (k != ord('q')):
    # Initialize curses
    stdscr = curses.initscr()
    curses.noecho()
    curses.cbreak()
    stdscr.keypad(True)
    # Start colors in curses
    curses.start_color()
    # curses.init_pair(pair_number, fg, bg)
    curses.init_pair(1, curses.COLOR_CYAN, curses.COLOR_BLACK)
    curses.init_pair(2, curses.COLOR_RED, curses.COLOR_BLACK)
    curses.init_pair(3, curses.COLOR_BLACK, curses.COLOR_WHITE)
    
    # getmaxyx() provides the window dimensions
    height, width = stdscr.getmaxyx()
#    def draw_menu(stdscr):
    cursor_x = 0
    cursor_y = 0
    # Clear and refresh the screen for a blank canvas
    stdscr.clear()
    stdscr.refresh()    

    if (k == ord('1')):
        curses.endwin()
        subprocess.call('clear')
        cmd_library.execute_cmd(['sh','./CPU_Frequency_Test', '-d', '/tmp/', '-p', 'CPU_Freq'])
        input("Press enter to continue...")
        print ("")          
    elif (k == ord('2')):
        curses.endwin()
        subprocess.call('clear')
        cmd_library.execute_cmd(['sh','./memoryHotPlugTest.sh', '-i', sutIpAddress, 
            '-d','/tmp/', '-p', 'mem_Hot_Plug'])
        input("Press enter to continue...")
        print ("")          
#        cmd_library.execute_cmd(['sh','./memoryHotPlugTest.sh', '-i', '10.1.1.3', '-d','/tmp/', '-p', 'mem_Hot_Plug-'])
    elif (k == ord('3')):
        curses.endwin()
        subprocess.call('clear')
        cmd_library.execute_cmd(['sh','./cpuHotPlugTest.sh', '-i', sutIpAddress, 
            '-d','/tmp/', '-p', 'cpu_Hot_Plug'])
        input("Press enter to continue...")
        print ("")          
#        cmd_library.execute_cmd(['sh','./cpuHotPlugTest.sh', '-i', '10.1.1.3', '-d','/tmp/', '-p', 'cpu_Hot_Plug-'])    
    cursor_x = max(0, cursor_x) # with two or more args, return the biggest arg
    cursor_x = min(width-1, cursor_x) # with to or more args, return smallest arg

    cursor_y = max(0, cursor_y)
    cursor_y = min(height-1, cursor_y)

    # Declaration of strings
    title = "Please select a test:"[:width-1] #Display string up to width-1 of screen
    title_test1 = "1 - CPU Frequency Test"[:width-1]
    title_test2 = "2 - Memory Hot Plug Test"[:width-1]
    title_test3 = "3 - CPU Hot Plug Test"[:width-1]
#    keystr = "Last key pressed: {}".format(k)[:width-1]
    #statusbarstr = "Press 'q' to exit | STATUS BAR | Pos: {}, {}".format(cursor_x, cursor_y)
    statusbarstr = "Press 'q' to exit | STATUS BAR" 
#    if k == 0:
#        keystr = "No key press detected..."[:width-1]

    # Centering calculations
    # // is floor division (rounds down to the nearest whole number)
    start_x_title = int(width - (width- 2 ))
    start_x_test = int(width - (width- 2 ))
#    start_x_keystr = int(width - (width- 2 ))
    start_y = int(height - (height -2))

    # Render status bar
    # attron() adds attribute from the "background" set applied to all writes
    # to the current window. attroff() removes it.
    stdscr.attron(curses.color_pair(3))
    stdscr.addstr(height-1, 0, statusbarstr)
    stdscr.addstr(height-1, len(statusbarstr), " " * (width - len(statusbarstr) - 1))
    stdscr.attroff(curses.color_pair(3))

    # Turning on attributes for title
#    stdscr.attron(curses.color_pair(2))
    stdscr.attron(curses.A_BOLD)

    # Rendering title
    stdscr.addstr(start_y, start_x_title, title)

    # Turning off attributes for title
#    stdscr.attroff(curses.color_pair(2))
    stdscr.attroff(curses.A_BOLD)

    # Print rest of text
    stdscr.addstr(start_y + 2, start_x_test, title_test1)
    stdscr.addstr(start_y + 3, start_x_test, title_test2)
    stdscr.addstr(start_y + 4, start_x_test, title_test3)
    #stdscr.addstr(start_y + 3, (width - (width - 2)), '-' * 4)
#    stdscr.addstr(start_y + 5, start_x_keystr, keystr)
#    stdscr.move(cursor_y, cursor_x) # Moves the cursor

    # Refresh the screen
    stdscr.refresh()

    # Wait for next input
    k = stdscr.getch()

curses.endwin()
#def main():
#     Initializes curses (stdscr = curses.initscr(), curses.noecho(), curses.cbreak(), stdscr.keypad(1))
#    curses.wrapper(draw_menu)

#if __name__ == "__main__":
#    main()
