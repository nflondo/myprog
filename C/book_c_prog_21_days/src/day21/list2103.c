/* list2103.c - A simple program with a  */
/*              quit application dialog. */

#include <gtk/gtk.h>
#include "yesno.h"

int delete_func(GtkWidget *widget, gpointer data);
void button_func(GtkWidget *widget, gpointer data);

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *button;
    
    gtk_init(&argc, &argv);
    
    /* Create the main window. */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize(GTK_WIDGET(window), 180, 120);
    gtk_window_set_title(GTK_WINDOW(window), __FILE__);
    
    gtk_signal_connect(GTK_OBJECT(window), "delete_event",
                       GTK_SIGNAL_FUNC(delete_func), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    
    /* Create button. */
    button = gtk_button_new_with_label("Button");
    gtk_signal_connect(GTK_OBJECT(button), "clicked", 
             GTK_SIGNAL_FUNC(button_func), NULL);
    
    gtk_container_add(GTK_CONTAINER(window), button);

    /* Make everything visible. */
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}

int delete_func(GtkWidget *widget, gpointer pdata)
{    
    if (yes_no_dialog("Quit?", "Quit application?"))
    {
        gtk_main_quit();
        return FALSE;
    }
    return TRUE;
}

void button_func(GtkWidget *widget, gpointer pdata)
{    
    g_print("Click\n");
}

