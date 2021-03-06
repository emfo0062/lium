#include <gtk/gtk.h>
#include <gnome.h>
#include "interface.h"
#include "calc.h"

/*
  Global variables
  */
GtkWidget *app;     //!< Main application window
GtkWidget *entryNr; //!< Entry widget for number of resistors
GtkWidget *entryV;  //!< Entry widget for voltage
GtkWidget *entryR1; //!< Entry widget for resistor value number 1
GtkWidget *entryR2; //!< Entry widget for resistor value number 2
GtkWidget *entryR3; //!< Entry widget for resistor value number 3
GtkWidget *radioSerial; //!< Radio buttons for serial connection type
GtkWidget *radioParalell; //!< Radio buttons for parallel connection type

static GnomeUIInfo filemenu[] = {
  GNOMEUIINFO_MENU_EXIT_ITEM ( closeApp, NULL ),
  GNOMEUIINFO_END
};//!< File menu item
static GnomeUIInfo helpmenu[] = {
  GNOMEUIINFO_MENU_ABOUT_ITEM ( onAboutActivate, NULL ),
  GNOMEUIINFO_END
};//!< Help menu item
static GnomeUIInfo menubar[] = {
  GNOMEUIINFO_MENU_FILE_TREE (filemenu),
  GNOMEUIINFO_MENU_HELP_TREE (helpmenu),
  GNOMEUIINFO_END
};//!< Menubar for the application

GtkWidget *createMainWindow( void )
{
  GtkWidget *app;//!< Main container
  GtkWidget *buttonCalc, *buttonClose; 
  GtkWidget *labelHeader;
  GtkWidget *label;
  GtkWidget *boxResistors, *boxConnType;
  GtkWidget *hbox, *vbox;

  // Create new Gnome application
  app = gnome_app_new("gnome1","Menus, menus, menus");

  // Set window properties
  gtk_window_set_title(GTK_WINDOW(app), "Den mest fantastiska elektronikkalkylatorn");
  gtk_window_set_position(GTK_WINDOW(app), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(app), 300, 200);
  gnome_app_create_menus( GNOME_APP(app), menubar);

  // Labels
  labelHeader = gtk_label_new("Räkna ut resistansen v1.0");
  label       = gtk_label_new("Typ av koppling:");

  // Entry
  entryNr = gtk_spin_button_new_with_range(1,3,1);
  entryV  = gtk_spin_button_new_with_range(56.34,10000,0.01);
  entryR1 = gtk_spin_button_new_with_range(1234.5 ,1000000000,0.1);
  entryR2 = gtk_spin_button_new_with_range(4321.0,1000000000,0.1);
  entryR3 = gtk_spin_button_new_with_range(5555.5,1000000000,0.1);
  
  // Buttons
  buttonCalc    = gtk_button_new_with_label("Räkna ut");
  buttonClose   = gtk_button_new_with_label("Avsluta");
  radioSerial   = gtk_radio_button_new(NULL);
  radioParalell = gtk_radio_button_new_from_widget( GTK_RADIO_BUTTON( radioSerial ));

  // Set callback functions
  g_signal_connect( GTK_OBJECT (app), "destroy", GTK_SIGNAL_FUNC (closeApp), NULL );
  g_signal_connect( GTK_OBJECT (buttonCalc), "clicked", GTK_SIGNAL_FUNC (buttonClicked), NULL );
  g_signal_connect( GTK_OBJECT (buttonClose), "clicked", GTK_SIGNAL_FUNC (closeApp), NULL );

  // Boxes
  boxResistors = gtk_vbox_new(FALSE, 5);
  boxConnType = gtk_vbox_new(TRUE, 5);
  hbox = gtk_hbox_new(TRUE, 5);
  vbox = gtk_vbox_new(FALSE, 10);

  // Packing boxes and adding labels
  gtk_box_pack_start(GTK_BOX(boxConnType), label, TRUE, FALSE, 5);
  addWidgetWithLabel( GTK_CONTAINER( boxConnType ), "Seriell", radioSerial );
  addWidgetWithLabel( GTK_CONTAINER( boxConnType ), "Parallell", radioParalell );
  addWidgetWithLabel( GTK_CONTAINER( boxConnType ), "Spänning (V):", entryV );
  gtk_box_pack_start(GTK_BOX(boxConnType), buttonClose, TRUE, FALSE, 5);

  addWidgetWithLabel( GTK_CONTAINER(boxResistors), "Antal resistorer:", entryNr);
  addWidgetWithLabel( GTK_CONTAINER(boxResistors), "Resistor #1:", entryR1);
  addWidgetWithLabel( GTK_CONTAINER(boxResistors), "Resistor #2:", entryR2);
  addWidgetWithLabel( GTK_CONTAINER(boxResistors), "Resistor #3:", entryR3);

  gtk_box_pack_start(GTK_BOX(boxResistors), buttonCalc, TRUE, FALSE, 5);
  
  gtk_box_pack_start(GTK_BOX(hbox), boxConnType, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), boxResistors, FALSE, FALSE, 5);

  // Add containers to gnome application
  gnome_app_set_contents( GNOME_APP(app), hbox);

  // Return Gnome app
  return app;
}

void buttonClicked(GtkWidget *button, gpointer data)
{
  presResult(data);
}

void closeApp (GtkWidget *window, gpointer data)
{
  gtk_main_quit();
}

void onAboutActivate (GtkMenuItem * menuItem, gpointer userData)
{
  const char * authors[] = {"Petter L", NULL};
  GtkWidget *about = gnome_about_new( "Tema 11", "1.0",
      "(c) Petter",
      "LiUM",
      (const char ** ) authors, NULL,
      "Bertil Johansson", NULL);
  gtk_widget_show(about);
}

void addWidgetWithLabel( GtkContainer *box, gchar *caption, GtkWidget *widget)
{
  GtkWidget *label = gtk_label_new(caption);
  GtkWidget *hbox = gtk_hbox_new(TRUE,4);

  gtk_container_add(GTK_CONTAINER(hbox), label);
  gtk_container_add(GTK_CONTAINER(hbox), widget);

  gtk_container_add(box,hbox);
}

void presResult( gpointer data )
{
  float resistors[3] = {0,0,0};
  char conn         = gtk_toggle_button_get_active((GtkToggleButton *) radioSerial) ? 'S': 'P';
  int nrOfResistors = gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON( entryNr ) );
  float voltage     = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryV ) );
  resistors[0]       = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryR1 ) );
  resistors[1]       = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryR2 ) );
  resistors[2]       = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryR3 ) );
  calcValues(nrOfResistors,conn,voltage,resistors);
  showPopUpWithResult();
}

GtkWidget *createResultPopUp ( void )
{
  GtkWidget *dialog = gtk_dialog_new_with_buttons ("Resultat",
      (GtkWindow*) app,
      GTK_DIALOG_MODAL,
      GTK_STOCK_OK,
      GTK_RESPONSE_ACCEPT,
      NULL);
 
  //Create labels
  GtkWidget *vbox = GTK_DIALOG(dialog)->vbox;

  gchar power[1024];
  sprintf(power, "Effekt: %.2f W", getPower());
  GtkWidget *lPower = gtk_label_new(power);
  gtk_container_add(GTK_CONTAINER(vbox), lPower);

  gchar totRes[1024];
  sprintf(totRes, "Ersättningsresistans: %.2f ohm", getResistance());
  GtkWidget *lRes = gtk_label_new(totRes);
  gtk_container_add(GTK_CONTAINER(vbox), lRes);

  gchar comp[1024];
  sprintf(comp, "Ersättningsresistanser i E12-serien kopplade i serie: %s", getComponentStr());
  GtkWidget *lComp = gtk_label_new(comp);
  gtk_container_add(GTK_CONTAINER(vbox), lComp);

  gtk_widget_show_all( GTK_WIDGET (GTK_DIALOG (dialog)->vbox ) );
  
  return dialog;
}
void showPopUpWithResult( void )
{
  // Show result
  GtkWidget *dialog = createResultPopUp();
  int result = gtk_dialog_run((GtkDialog *)dialog);
  gtk_widget_destroy(dialog);
}
