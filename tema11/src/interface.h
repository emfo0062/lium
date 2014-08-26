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

  @param box Pointer to the container to put the label and widget in
  @param caption Caption of the label
  @param widget The widget to add in the container
  */
void addWidgetWithLabel( GtkContainer *box, gchar *caption, GtkWidget *widget);

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
  
  @param menuItem Menu item that was clicked
  @param userData User data passed on by callback function
*/
void onAboutActivate (GtkMenuItem *menuItem, gpointer userData);

/**
  @brief Presents the result with a pop up

  @param data Data passed to the function is ignored 
*/
void presResult( gpointer data );
/**
  @brief Creates the result pop up widget

  @return Pop up widget
  */
GtkWidget *createResultPopUp ( void );
/**
  @brief Shows the pop up with result

*/
void showPopUpWithResult( void );
