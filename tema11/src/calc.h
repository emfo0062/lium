/**************************************************
*
* calc.h
*
***************************************************/
/**
  Returns the calculated power value

  @return power as a float
  */
float getPower(void);

/**
  */
float getComponents(unsigned int);

/**
  */
char* getComponentStr( void );

/**
  */
float getResistance(void);

/**
  @brief Calculates the different electrotest
  results based on the input parameters

  @param int resistor count
  @param char connection type
  @param float voltage
  @param float [3] for the resistors

  */
int calcValues(int,char,float,float[]);
