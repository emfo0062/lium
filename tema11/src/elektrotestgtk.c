/**************************************************
*
* Tema 11
*
***************************************************/

#include <gtk/gtk.h>
#include <stdio.h>

static int count = 0;

/**
  Callback function for calculate button
*/
void button_clicked(GtkWidget *button, gpointer data)
{
  printf("%s pressed %d time(s)\n", (char *) data, ++count);
}

/**
  Close the app properly
*/
void closeApp (GtkWidget *window, gpointer data)
{
  gtk_main_quit();
}

/**

*/
gboolean delete_event (GtkWidget *widget, GdkEvent *event, gpointer data)
{
  printf("In delete_event");
  return FALSE;
}

/**
  Setting up the GTK
*/
int main ( int argc, char *argv[] )
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *label1, *label2, *label3;
  GtkWidget *hbox, *vbox;

  gtk_init(&argc,&argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // Set window properties
  gtk_window_set_title(GTK_WINDOW(window), "The Window Title");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

  // Labels
  label1 = gtk_label_new("Label 1");
  label2 = gtk_label_new("Label 2");
  label3 = gtk_label_new("Label 3");

  // Boxes
  hbox = gtk_hbox_new(TRUE, 5);
  vbox = gtk_vbox_new(FALSE, 10);

  // Buttons
  button = gtk_button_new_with_label("Hello World!");

  // Set callback functions
  g_signal_connect(GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC (closeApp), NULL);
  g_signal_connect(GTK_OBJECT (window), "delete_event", GTK_SIGNAL_FUNC (delete_event), NULL);
  g_signal_connect(GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC (button_clicked), "Button 1");

  // Packing boxes
  gtk_box_pack_start(GTK_BOX(vbox), label1, TRUE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), label2, TRUE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, FALSE, 5);

  gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), label3, FALSE, FALSE, 5);

  // Add containers
  gtk_container_add(GTK_CONTAINER(window), hbox);

  // Show widgets 
  //gtk_widget_show(button);
  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
