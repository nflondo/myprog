/* list2101.c - A minimal GTK+ program. */

#include <gtk/gtk.h>

void destroy_func(GtkWidget *widget, gpointer data);

int main(int argc, char *argv[])
{
    GtkWidget *main_win;

    gtk_init(&argc, &argv);
    
    main_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize(GTK_WIDGET(main_win), 180, 120);
    gtk_window_set_title(GTK_WINDOW(main_win), __FILE__);

    gtk_signal_connect(GTK_OBJECT(main_win), "destroy",
                       GTK_SIGNAL_FUNC(destroy_func), NULL);

    /* Make the window visible. */
    gtk_widget_show(main_win);
    
    gtk_main();
    
    g_print("About to exit main().\n");
    return 0;
}

void destroy_func(GtkWidget *widget, gpointer pdata)
{
    g_print("Quitting : Received destroy signal.\n");
    gtk_main_quit();
}
