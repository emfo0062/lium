/**
* @mainpage
*
* This graphics application uses the electrotest
* liraries produced in tema 9
*
* @author Petter Lerenius
* @date 27/8-2014
* @version 1.0
* @file elektrotestgtk.c
***************************************************/

#include <gtk/gtk.h>
#include <gnome.h>
#include <stdio.h>
#include <string.h>
#include "elektrotestgtk.h"
#include "interface.h"
#include "calc.h"




int main ( int argc, char *argv[] )
{
  GtkWidget *window;
  // Initialize the gnome application and create the main window
  gnome_program_init("Elektrotest", "1.0", LIBGNOMEUI_MODULE, argc, argv, GNOME_PARAM_NONE);
  window = createMainWindow();

  // Show widgets 
  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
