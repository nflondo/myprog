/* filename.c - A filename selection dialog. */
#include <gtk/gtk.h>
#include <string.h>
#include "filename.h"

typedef struct
{   GtkWidget *filesel;
    gchar     *filename;
    gint      len ;
} FILEDATA ;

static void filename_ok(GtkWidget *widget, FILEDATA *filedata);
static void filename_cancel(GtkWidget *widget, GtkWidget *filesel);

int filename_dialog(gchar *title, gchar *filename, gint namelen)
{
    GtkWidget *filesel;
    FILEDATA  filedata;
    
    if (filename == NULL)
        return FALSE;
    filename [0] = 0;
    
    filesel = gtk_file_selection_new("Save file as :");
    gtk_window_set_modal(GTK_WINDOW(filesel), TRUE);
    gtk_widget_show(filesel);
    
    filedata.filesel = filesel;
    filedata.filename = filename;
    filedata.len = namelen;

    gtk_signal_connect(
            GTK_OBJECT(GTK_FILE_SELECTION(filesel)->ok_button), 
            "clicked", (GtkSignalFunc) filename_ok, &filedata);
    gtk_signal_connect(
            GTK_OBJECT(GTK_FILE_SELECTION(filesel)->cancel_button), 
            "clicked", (GtkSignalFunc) filename_cancel, filesel);
    gtk_signal_connect(GTK_OBJECT(filesel), "destroy",
            GTK_SIGNAL_FUNC(filename_cancel), filesel);
        
    gtk_main();

    if (strlen (filename) > 0)
        return TRUE;

    return FALSE;    
}

static
void filename_ok(GtkWidget *widget, FILEDATA *filedata)
{
    gchar *selectname;
    
    selectname = gtk_file_selection_get_filename(
                       GTK_FILE_SELECTION(filedata->filesel));

    if (strlen (selectname) < filedata->len)
        strcpy (filedata->filename, selectname);

    gtk_widget_destroy(filedata->filesel);
    gtk_main_quit();
}

static
void filename_cancel(GtkWidget *widget, GtkWidget *filesel)
{
    gtk_widget_destroy(filesel);
    gtk_main_quit();
}


