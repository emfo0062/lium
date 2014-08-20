/**************************************************
*
* calc.h
*
***************************************************/
/**
  @brief Returns the calculated power value

  @return Power as a float
  */
float getPower(void);

/**
  @brief Returns the index:th component value

  @param unsigned int index of the component
  @return Component as a float
  */
float getComponentValue(unsigned int index );

/**
  @brief Returns a component string describing the
  different components matching the e-series
  resistors

  @return Components as a string
  */
char* getComponentStr( void );

/**
  @brief Returns the equivalent total resistance

  @return The global float totRes
  */
float getResistance(void);

/**
  @brief Calculates the different electrotest
  results based on the input parameters

  @param int resistor count
  @param char connection type
  @param float voltage
  @param float [3] for the resistors

  @return 0 if calculation went well, otherwise not zero
  */
int calcValues(int,char,float,float[3]);
