/**************************************************
*
* calc.c
*
***************************************************/
#include <stdio.h>
#include <string.h>
#include <resistance.h>
#include <component.h>
#include <power.h>

float power    = 1234;    //!< Global variable for power
float comp[3]  = {1,2,3}; //!< Global variable for component values
float totRes   = 0.123;   //!< Global variable for equivalent resistor value
float voltage  = 15.0;    //!< Global variable for voltage value
char  compStr[1024] = ""; //!< Global variable for component string

float getPower( void )
{
  return power;
}

float getComponentValue( unsigned int index )
{
  if (index < 3)
  {
    return comp[index];
  }
  return -1;
}

char* getComponentStr( void )
{
  int i, len;
  char tmpStr[128];
  float *fp=&comp[0];
  compStr[0] = '\0';
  for (i = e_resistance(totRes, &comp[0]); i>0; i--) {
    sprintf(tmpStr,"%1.0f", *fp++);
    strcat(compStr,tmpStr);
    if (i>1)
    {
      strcat(compStr,", ");
    }
  }

  return compStr;
}

float getResistance( void )
{
  return totRes;
}

int calcValues(int count, char conn, float volt, float resistors[3])
{
  int i;
  totRes = calc_resistance(count,conn,resistors);
  if (totRes == -1) {printf ("Error - Misslyckades med att räkna ut ersättningsresistans\n"); return -1;}
  power = calc_power_r(volt, totRes);
  
  return 0;
}
