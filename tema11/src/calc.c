/**************************************************
*
* calc.c
*
***************************************************/

int power = 1234;
int comp[3] = {1,2,3};
float resTot = 0.123;
/**
*/
int getPower()
{
  return power;
}

/**
*/
int getComponents(unsigned int index)
{
  if (index < 3)
  {
    return comp[index];
  }
  return -1;
}

/**
*/
float getResistors()
{
  return resTot;
}

/**
*/
int calcValues()
{
  return 1111;
}
