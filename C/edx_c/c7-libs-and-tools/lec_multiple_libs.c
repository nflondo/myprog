    #include <stdio.h>
    #include <ncursesw/curses.h>
    #include <ncursesw/menu.h>
    #include <stdlib.h>

    int main(void) {
    	ITEM **my_items;
    	int c;
    	MENU *my_menu;
    	int n_choices, i;
    	char *choices[] = {
    	    "Menu 1",
    	    "Menu 2",
    	    "Menu 3",
    	    "Menu 4"
    	};
    	char *descriptions[] = {
    		"do this",
    		"do that",
    		"do ....",
    		"do ????"
    	};
    	
    	initscr();
    	cbreak();
    	noecho();
    	keypad(stdscr, TRUE);
    	
    	n_choices = sizeof(choices) / sizeof(choices[0]);
    	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    	
    	for (i=0; i<n_choices; i++) {
    	    my_items[i] = new_item(choices[i], descriptions[i]);
    	}
    	my_items[n_choices] = (ITEM *)NULL;
    	
    	my_menu = new_menu((ITEM **)my_items);
    	mvprintw(LINES - 2, 0, "q to quit");
    	post_menu(my_menu);
    	refresh();
    	
    	while ((c = getch()) != 'q') {
    	    if (c==KEY_DOWN) {
    	        menu_driver(my_menu, REQ_DOWN_ITEM);
    	    } else if (c==KEY_UP) {
    	        menu_driver(my_menu, REQ_UP_ITEM);
    	    }
    	}
    	
    	for (i=0; i<=n_choices; i++) {
    		free_item(my_items[i]);
    	}
    	free_menu(my_menu);
    	endwin();
    	return 0;
    }

