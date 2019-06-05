/* list2102.c - A GTK+ program with push buttons. */

#include <gtk/gtk.h>

void button_func(GtkWidget *widget, gpointer data);
void destroy_func(GtkWidget *widget, gpointer data);

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *vbox;
    int       bdata1, bdata2;
    
    gtk_init(&argc, &argv);
    
    /* Create the main window. */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize(GTK_WIDGET(window), 180, 120);
    gtk_window_set_title(GTK_WINDOW(window), __FILE__);
    
    gtk_signal_connect(GTK_OBJECT(window), "destroy",
                       GTK_SIGNAL_FUNC(destroy_func), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    
    vbox = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    /* Setup first button. */
    bdata1 = 0;
    button = gtk_button_new_with_label("Button1");
    gtk_signal_connect(GTK_OBJECT(button), "clicked", 
             GTK_SIGNAL_FUNC(button_func), (gpointer)&bdata1);
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, FALSE, 0);
    gtk_widget_show(button);
    
    /* Setup second button. */
    bdata2 = 1;
    button = gtk_button_new_with_label("Button2");
    gtk_signal_connect(GTK_OBJECT(button), "clicked", 
             GTK_SIGNAL_FUNC(button_func), (gpointer)&bdata2);
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, FALSE, 0);
    gtk_widget_show(button);

    /* Make everything visible. */
    gtk_widget_show(vbox);    
    gtk_widget_show(window);
    
    gtk_main();
    
    return 0;
}

void button_func(GtkWidget *widget, gpointer pdata)
{    
    static int count [2] = { 0, 0 };
    int index ;
    
    index = *((int*)pdata);
    count [index]++;
    g_print("Button %d click %d.\n",index+1,count [index]);
}

void destroy_func(GtkWidget *widget, gpointer pdata)
{
    g_print("Quitting : Received destroy signal.\n");
    gtk_main_quit();
}
