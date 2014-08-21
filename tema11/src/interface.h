/**
  @brief Creates the main window for the application

  This function putts all the contaiers together to
  make up the application window.

  */
GtkWidget *createMainWindow( void );

/**
  @brief A helper function for labeled widgets

  Add a widget to a container with a label in front of it.
  It is a helper function to reduce code lines.

  @param box
  @param caption
  @param widget
  */
void addWidgetWithLabel( GtkContainer *, gchar *, GtkWidget * );

/**
  @brief Callback function for calculate button to present result

  Will call presResult function to present the result to 
  the user.

  @param button
  @param data
 */
void buttonClicked(GtkWidget *button, gpointer data);
/**
  @brief GTK function to close app properly
  
  Close the app properly by using gtk_main_quit()

  @param window
  @param data
*/
void closeApp (GtkWidget *window, gpointer data);
/**
  @brief Show About dialog when menu pressed
  
  @param GtkMenuItem
  @param gpointer
*/
void onAboutActivate (GtkMenuItem *, gpointer);

/**
  @brief Presents the result with a pop up

  @param gpointer Data to passed to the function is ignored 
*/
int presResult( gpointer );
/**
  @brief Creates the result pop up widget

  @param int Number of resistors
  @param char Type of connection 'S' Serial, 'P' Parallell
  @param float Voltage
  @param float[] Resistor values
  */
GtkWidget *createResultPopUp ( int, char, float, float [] );
/**
  @brief Shows the pop up with result

  @param int number of resistors
  @param char Type of connection 'S' Serial, 'P' Parallell
  @param float Voltage
  @param float[] Resistor values
*/
int showPopUpWithResult( int, char, float, float [] );
