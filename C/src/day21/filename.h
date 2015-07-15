/* filename.h - A header file for a self contained filename   */
/*              selection dialog box.                         */

/* The title parameter sets the title of the dialog box. The  */
/* filename that the use selects is copied into the filename  */
/* provided by the called. The filename string is assumed to  */
/* at least namelen characters in length.                     */

/* On success this functio returns TRUE. On failure (ie the   */
/* user clicks the cancel button) the function returns FALSE. */

int filename_dialog(gchar *title, gchar *filename, gint namelen);
