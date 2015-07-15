/* yesno.c - a general purpose yes/no dialog. */

#include <gtk/gtk.h>
#include "yesno.h"

static void yesno_func (GtkWidget *widget, gchar *yesno);

/* A static variable for the yes/no return value. */
static gint yesno;

int yes_no_dialog (gchar *title, gchar *labeltext)
{    
    GtkWidget *dialog, *label, *ybutton, *nbutton;
    GtkWidget *vbox, *hbox;

    /* Create the required widgets. */
    dialog  = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label   = gtk_label_new(labeltext);
    ybutton = gtk_button_new_with_label("   Yes   ");
    nbutton = gtk_button_new_with_label("   No    ");
    vbox    = gtk_vbox_new(FALSE, 0); 
    hbox    = gtk_hbox_new(FALSE, 0);

    /* Pack the widgets. */
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), ybutton, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), nbutton,  TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(dialog), vbox);
    
    gtk_widget_set_usize(GTK_WIDGET(dialog), 140, 80);
    gtk_window_set_title(GTK_WINDOW(dialog), title);
    gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
 
    /* Connect the signals. */
    gtk_signal_connect(GTK_OBJECT(ybutton), "clicked",
                        GTK_SIGNAL_FUNC(yesno_func), "yes");
    gtk_signal_connect(GTK_OBJECT(nbutton),  "clicked",
                        GTK_SIGNAL_FUNC(yesno_func), "no");
    gtk_signal_connect(GTK_OBJECT(dialog), "delete_event",
                GTK_SIGNAL_FUNC(gtk_main_quit), dialog);

    /* Make everything visible. */
    gtk_widget_show_all(dialog);
    
    /* Start gtk_main() for the dialog box. */
    gtk_main();
    
    /* Destroy the dialog box. */
    gtk_widget_destroy(dialog);

    return yesno;
}

static void yesno_func (GtkWidget *widget, gchar *yesnostr)
{ 
    if (yesnostr [0] == 'y')
        yesno = TRUE;
    else
        yesno = FALSE;

    gtk_main_quit();
}
