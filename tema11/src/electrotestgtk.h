/**
  @brief A helper function for labeled widgets

  Add a widget to a container with a label in front of it.
  It is a helper function to reduce code lines.

  @param box
  @param caption
  @param widget
  */
void add_widget_with_label( GtkContainer *box, gchar *caption, GtkWidget *widget);

/**
  @brief Callback function for calculate button to present result

  Will call presResult function to present the result to 
  the user.

  @param button
  @param data
 */
void button_clicked(GtkWidget *button, gpointer data);
/**
  @bried GTK function to close app properly
  
  Close the app properly by using gtk_main_quit()

  @param window
  @param data
*/
void closeApp (GtkWidget *window, gpointer data);

/**
  @brief delete event callback

  @param widget
  @param event
  @param data
*/
gboolean delete_event (GtkWidget *widget, GdkEvent *event, gpointer data);

