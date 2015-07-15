/* list2106.c - A simple (and incomplete) GTK+ text editor. */
#include <gtk/gtk.h>
#include <stdio.h>
#include "filename.h"

void destroy_func(GtkWidget *widget, gpointer data);
void menu_func(GtkWidget *widget, guint number);
GtkWidget *make_menu(GtkWidget  *window);
void file_save_dlg(GtkWidget *widget, gpointer pdata);
int save_file(char *filename);

static GtkWidget *textbox ;

int main(int argc, char *argv[])
{
    GtkWidget *window, *menubar, *vscrollbar;
    GtkWidget *vbox, *hbox;
    GdkFont   *textfont ;
    GtkStyle  *style;
    
    gtk_init(&argc, &argv);
    
    /* Create the main window. */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize(GTK_WIDGET(window), 400, 300);
    gtk_window_set_title(GTK_WINDOW(window), __FILE__);
    
    gtk_signal_connect(GTK_OBJECT(window), "destroy",
                       GTK_SIGNAL_FUNC(destroy_func), NULL);
    
    vbox = gtk_vbox_new(FALSE, 0);
    hbox = gtk_hbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    /* Create the menu bar. */    
    menubar = make_menu(window);
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, TRUE, 0);
    gtk_widget_show(menubar);    
    
    /* Create the text area. */
    textbox = gtk_text_new(NULL, NULL);
    vscrollbar = gtk_vscrollbar_new(GTK_TEXT(textbox)->vadj);

    gtk_text_set_editable(GTK_TEXT(textbox), TRUE);
    gtk_text_set_line_wrap(GTK_TEXT(textbox), FALSE);

    if ((textfont = gdk_font_load("7x13")) != NULL)
    {    
        style = gtk_widget_get_style(textbox);
        style->font = textfont;
        gtk_widget_set_style(textbox, style);
    }
 
    /* Pack the widgets in boxes. */
    gtk_box_pack_start(GTK_BOX(hbox), textbox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), vscrollbar, FALSE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    
    /* Make everything visible. */
    gtk_widget_show_all(window);

    gtk_main();
        
    return 0;
}

void destroy_func(GtkWidget *widget, gpointer pdata)
{
    gtk_main_quit();
}

/* Menu bar creation code. */

static GtkItemFactoryEntry menu_array[] = 
{    
  { "/_File"     , NULL        , NULL         , 0, "<Branch>" },
  { "/File/_Open", "<control>O", menu_func    , 0, NULL },
  { "/File/_Save", "<control>S", file_save_dlg, 0, NULL },
  { "/File/sep1" , NULL        , NULL         , 0, "<Separator>" },
  { "/File/Quit" , "<control>Q", gtk_main_quit, 0, NULL },
  
  { "/_Two"    , NULL, NULL     ,  0, "<Branch>" },
  { "/Two/_One", NULL, menu_func,  1, NULL },
  { "/Two/_Two", NULL, menu_func,  2, NULL },
  
  { "/_Menu3"     , NULL,  NULL,  0, "<Branch>" },
  { "/Menu3/Test1", NULL,  NULL,  0, "<ToggleItem>" },
  { "/Menu3/sep1" , NULL,  NULL,  0, "<Separator>" },
  { "/Menu3/Test2", NULL,  NULL,  0, "<RadioItem>" },
  { "/Menu3/Test3", NULL,  NULL,  0, "/Menu3/Test2" },
  { "/Menu3/Test4", NULL,  NULL,  0, "/Menu3/Test2" },

  { "/_Help"      , NULL,  NULL,  0, "<LastBranch>" },
  { "/_Help/About", NULL,  NULL,  0, NULL },
};

GtkWidget *make_menu(GtkWidget  *window)
{
    GtkWidget      *menubar;
    GtkItemFactory *itemfact;
    GtkAccelGroup  *accelgroup;
    
    gint msize = sizeof(menu_array) / sizeof(menu_array[0]);

    accelgroup = gtk_accel_group_new();
    gtk_accel_group_attach(accelgroup, GTK_OBJECT(window));

    itemfact = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<main>", 
                                             accelgroup);
    gtk_item_factory_create_items(itemfact, msize, menu_array, NULL);

    menubar = gtk_item_factory_get_widget(itemfact, "<main>");
          
    return menubar;
}

void menu_func(GtkWidget *widget, guint number)
{
    if (number)
        g_print("Number : %d\n", number);
    else
        g_print("Hello!\n");
}

/* File save dialog callback functions. */
void file_save_dlg(GtkWidget *widget, gpointer pdata)
{
    gchar filename [512];
    
   if (filename_dialog("Save file as:", filename, 512))
        save_file (filename);
}

int save_file(char *filename)
{
    FILE *file;
    int  length;
    char *cptr;
    
    if ((file = fopen(filename, "w")) == NULL)
        return 1 ;
        
    length = gtk_text_get_length(GTK_TEXT(textbox));
    cptr = gtk_editable_get_chars(GTK_EDITABLE(textbox),0,length);

    if (cptr)
        fwrite(cptr, length, 1, file);
        
    fclose(file);
    return 0 ;
}

