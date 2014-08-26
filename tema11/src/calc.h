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

  @param index The index of the component
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

  @param count number of resistors
  @param connection type
  @param volt voltage level
  @param resistors resistor values

  @return 0 if calculation went well, otherwise not zero
  */
int calcValues(int count,char connection,float volt,float resistors[3]);
