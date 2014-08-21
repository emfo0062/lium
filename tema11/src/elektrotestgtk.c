/**
* @mainpage
*
* This graphics application uses the electrotest
* liraries produced in tema 9
*
* @author Petter Lerenius
* @date 27/5-2014
* @version 1.0
* @file electrotestgtk.c
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
  GtkWidget *buttonCalc, *buttonClose;
  GtkWidget *labelHeader;
  GtkWidget *label;
  GtkWidget *boxResistors, *boxConnType;
  GtkWidget *hbox, *vbox;

  gnome_program_init("gnome1", "1.0", LIBGNOMEUI_MODULE, argc, argv, GNOME_PARAM_NONE);
  window = gnome_app_new("gnome1","Menus, menus, menus");

  // Set window properties
  gtk_window_set_title(GTK_WINDOW(window), "The Most Fabulous Electronics Calculator");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  gnome_app_create_menus( GNOME_APP(window), menubar);

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
  gnome_app_set_contents( GNOME_APP(window), hbox);

  // Show widgets 
  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
