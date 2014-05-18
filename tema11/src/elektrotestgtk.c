/**************************************************
*
* Tema 11
*
***************************************************/

#include <gtk/gtk.h>
#include <stdio.h>
#include "calc.h"


/**
  Globals
  */
GtkWidget *entryNr;
GtkWidget *entryr1, *entryr2, *entryr3;
GtkWidget *radioSerial,*radioParalell;

void add_widget_with_label( GtkContainer *, gchar *, GtkWidget *);

/**
  Callback function for calculate button
*/
void button_clicked(GtkWidget *button, gpointer data)
{
  presResult(data);
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
  GtkWidget *buttonCalc, *buttonClose;
  GtkWidget *labelHeader;
  GtkWidget *label;
  GtkWidget *boxResistors, *boxConnType;
  GtkWidget *hbox, *vbox;

  gtk_init(&argc,&argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // Set window properties
  gtk_window_set_title(GTK_WINDOW(window), "The Most Fabulous Electrics Calculator");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

  // Labels
  labelHeader = gtk_label_new("Calculate the Resistors v 1.0");
  label   = gtk_label_new("Do you have them in:");

  // Entry
  entryNr = gtk_spin_button_new_with_range(1,3,1);
  entryr1 = gtk_spin_button_new_with_range(1234,1000000000,0.1);
  entryr2 = gtk_spin_button_new_with_range(4321,1000000000,0.1);
  entryr3 = gtk_spin_button_new_with_range(5555,1000000000,0.1);
  
  // Boxes
  boxResistors = gtk_vbox_new(FALSE, 5);
  boxConnType = gtk_vbox_new(TRUE, 5);
  hbox = gtk_hbox_new(TRUE, 5);
  vbox = gtk_vbox_new(FALSE, 10);

  // Buttons
  buttonCalc = gtk_button_new_with_label("Calculate");
  buttonClose = gtk_button_new_with_label("Exit");
  radioSerial = gtk_radio_button_new(NULL);
  radioParalell = gtk_radio_button_new_from_widget( GTK_RADIO_BUTTON( radioSerial ));

  // Set callback functions
  g_signal_connect( GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC (closeApp), NULL );
  g_signal_connect( GTK_OBJECT (window), "delete_event", GTK_SIGNAL_FUNC (delete_event), NULL );
  g_signal_connect( GTK_OBJECT (buttonCalc), "clicked", GTK_SIGNAL_FUNC (button_clicked), entryNr );
  g_signal_connect( GTK_OBJECT (buttonClose), "clicked", GTK_SIGNAL_FUNC (closeApp), NULL );

  // Packing boxes
  add_widget_with_label( GTK_CONTAINER(boxResistors), "Number of resistors:", entryNr);
  add_widget_with_label( GTK_CONTAINER(boxResistors), "Resistor 1:", entryr1);
  add_widget_with_label( GTK_CONTAINER(boxResistors), "Resistor 2:", entryr2);
  add_widget_with_label( GTK_CONTAINER(boxResistors), "Resistor 3:", entryr3);

  gtk_box_pack_start(GTK_BOX(boxResistors), buttonCalc, TRUE, FALSE, 5);

  gtk_box_pack_start(GTK_BOX(boxConnType), label, TRUE, FALSE, 5);
  add_widget_with_label( GTK_CONTAINER( boxConnType ), "Serial", radioSerial );
  add_widget_with_label( GTK_CONTAINER( boxConnType ), "Paralell", radioParalell );
  gtk_box_pack_start(GTK_BOX(boxConnType), buttonClose, TRUE, FALSE, 5);
  
  gtk_box_pack_start(GTK_BOX(hbox), boxResistors, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), boxConnType, FALSE, FALSE, 5);

  // Add containers
  gtk_container_add(GTK_CONTAINER(window), hbox);

  // Show widgets 
  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}

void add_widget_with_label( GtkContainer *box, gchar *caption, GtkWidget *widget)
{
  GtkWidget *label = gtk_label_new(caption);
  GtkWidget *hbox = gtk_hbox_new(TRUE,4);

  gtk_container_add(GTK_CONTAINER(hbox), label);
  gtk_container_add(GTK_CONTAINER(hbox), widget);

  gtk_container_add(box,hbox);
}

int presResult( gpointer data )
{
  int i;
  float resistor[3] = {0,0,0};
  char powerStr[19];
  sprintf(powerStr,"%d", getPower());
  int nrOfResistors = gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON( entryNr ) );
  resistor[0] = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryr1 ) );
  resistor[1] = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryr2 ) );
  resistor[2] = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryr3 ) );
  printf("Hej hopp!\n# of resistors: %d\n", nrOfResistors);
  for (i = 0; i < nrOfResistors; i++)
  {
    printf("Resistor #%d: %.2f\n",i, resistor[i]);
  }
  char conn = gtk_toggle_button_get_active(radioSerial) ? 'S': 'P';
  calcValues(nrOfResistors,conn,resistor);
  return 0;
}
