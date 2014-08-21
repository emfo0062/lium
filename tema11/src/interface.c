
/*
  Global variables
  */
GtkWidget *window;  //!< Main application window
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
};
static GnomeUIInfo helpmenu[] = {
  GNOMEUIINFO_MENU_ABOUT_ITEM ( onAboutActivate, NULL ),
  GNOMEUIINFO_END
};
static GnomeUIInfo menubar[] = {
  GNOMEUIINFO_MENU_FILE_TREE (filemenu),
  GNOMEUIINFO_MENU_HELP_TREE (helpmenu),
  GNOMEUIINFO_END
};

void button_clicked(GtkWidget *button, gpointer data)
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
      "Translators", NULL);
  gtk_widget_show(about);
}
gboolean delete_event (GtkWidget *widget, GdkEvent *event, gpointer data)
{
  printf("In delete_event");
  return FALSE;
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
  char conn         = gtk_toggle_button_get_active((GtkToggleButton *) radioSerial) ? 'S': 'P';
  int nrOfResistors = gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON( entryNr ) );
  float voltage     = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryV ) );
  resistors[0]       = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryR1 ) );
  resistors[1]       = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryR2 ) );
  resistors[2]       = gtk_spin_button_get_value( GTK_SPIN_BUTTON( entryR3 ) );
  calcValues(nrOfResistors,conn,voltage,resistors);
  return showPopUpWithResult(nrOfResistors,conn,voltage,resistors);
}

GtkWidget *createResultPopUp ( int nrOfResistors, char conn, float voltage, float resistors[] )
{
  GtkWidget *dialog = gtk_dialog_new_with_buttons ("Result",
      (GtkWindow*) window,
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
int showPopUpWithResult( int nrOfResistors, char conn, float voltage, float resistors[] )
{
  // Show result
  GtkWidget *dialog = createResultPopUp(nrOfResistors,conn,voltage,resistors);
  int result = gtk_dialog_run((GtkDialog *)dialog);
  gtk_widget_destroy(dialog);
  return 0;
}

int createMenu ( void )
{
  
}