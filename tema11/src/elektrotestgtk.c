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
GtkWidget *entryNr, *entryV;
GtkWidget *entryR1, *entryR2, *entryR3;
GtkWidget *radioSerial,*radioParalell;
/**
  Add a widget to a container with a label in front of it.
  It is a helper function to reduce code lines.
  */
void add_widget_with_label( GtkContainer *, gchar *, GtkWidget *);

/**
  Callback function for calculate button to present result

  Will call presResult function to present the result to 
  the user.
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
  gtk_window_set_title(GTK_WINDOW(window), "The Most Fabulous Electronics Calculator");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

  // Labels
  labelHeader = gtk_label_new("Calculate the Resistors v 1.0");
  label       = gtk_label_new("Do you have them in:");

  // Entry
  entryNr = gtk_spin_button_new_with_range(1,3,1);
  entryV  = gtk_spin_button_new_with_range(56.34,10000,0.01);
  entryR1 = gtk_spin_button_new_with_range(1234.5 ,1000000000,0.1);
  entryR2 = gtk_spin_button_new_with_range(4321.0,1000000000,0.1);
  entryR3 = gtk_spin_button_new_with_range(5555.5,1000000000,0.1);
  
  // Buttons
  buttonCalc    = gtk_button_new_with_label("Calculate");
  buttonClose   = gtk_button_new_with_label("Exit");
  radioSerial   = gtk_radio_button_new(NULL);
  radioParalell = gtk_radio_button_new_from_widget( GTK_RADIO_BUTTON( radioSerial ));

  // Set callback functions
  g_signal_connect( GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC (closeApp), NULL );
  g_signal_connect( GTK_OBJECT (window), "delete_event", GTK_SIGNAL_FUNC (delete_event), NULL );
  g_signal_connect( GTK_OBJECT (buttonCalc), "clicked", GTK_SIGNAL_FUNC (button_clicked), NULL );
  g_signal_connect( GTK_OBJECT (buttonClose), "clicked", GTK_SIGNAL_FUNC (closeApp), NULL );

  // Boxes
  boxResistors = gtk_vbox_new(FALSE, 5);
  boxConnType = gtk_vbox_new(TRUE, 5);
  hbox = gtk_hbox_new(TRUE, 5);
  vbox = gtk_vbox_new(FALSE, 10);

  // Packing boxes
  gtk_box_pack_start(GTK_BOX(boxConnType), label, TRUE, FALSE, 5);
  add_widget_with_label( GTK_CONTAINER( boxConnType ), "Serial", radioSerial );
  add_widget_with_label( GTK_CONTAINER( boxConnType ), "Paralell", radioParalell );
  add_widget_with_label( GTK_CONTAINER( boxConnType ), "Voltage", entryV );
  gtk_box_pack_start(GTK_BOX(boxConnType), buttonClose, TRUE, FALSE, 5);

  add_widget_with_label( GTK_CONTAINER(boxResistors), "Number of resistors:", entryNr);
  add_widget_with_label( GTK_CONTAINER(boxResistors), "Resistor 1:", entryR1);
  add_widget_with_label( GTK_CONTAINER(boxResistors), "Resistor 2:", entryR2);
  add_widget_with_label( GTK_CONTAINER(boxResistors), "Resistor 3:", entryR3);

  gtk_box_pack_start(GTK_BOX(boxResistors), buttonCalc, TRUE, FALSE, 5);
  
  gtk_box_pack_start(GTK_BOX(hbox), boxConnType, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), boxResistors, FALSE, FALSE, 5);

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
  float resistors[3] = {0,0,0};
  char conn         = gtk_toggle_button_get_active(radioSerial) ? 'S': 'P';
  int nrOfResistors = gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON( entryNr ) );
  float voltage     = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryV ) );
  resistors[0]       = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryR1 ) );
  resistors[1]       = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryR2 ) );
  resistors[2]       = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryR3 ) );
  printf("Calc: %d, %c, %f, %f, %f, %f\n",nrOfResistors,conn,voltage,resistors[0],resistors[1],resistors[2]);
  calcValues(nrOfResistors,conn,voltage,resistors);
  return showPopUpWithResult();
}

int showPopUpWithResult( void )
{
  return 0;
}
