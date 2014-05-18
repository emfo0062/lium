/**************************************************
*
* calc.c
*
***************************************************/
#include <stdio.h>
#include <resistance.h>
#include <component.h>
#include <power.h>

float power = 1234;
float comp[3] = {1,2,3};
float totRes = 0.123;
float volt = 15.0;
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
  return totRes;
}

/**
*/
int calcValues(int count, char conn, float resistors[3])
{
  int i;
  totRes = calc_resistance(count,conn,resistors);
  if (totRes == -1) {printf ("Error - Misslyckades med att räkna ut ersättningsresistans\n"); return -1;}
  printf("Ersättningsresistans: %.2f ohm\n",totRes);
  power = calc_power_r(volt, totRes);
  printf("Effekt: %.2f W\n", power);
  printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
  float *fp=&comp[0];
  for (i = e_resistance(totRes, &comp[0]); i>0; i--){
    printf("%1.0f", *fp++);
    if (i>1)
      printf(", ");
  }
  printf("\n");
  
  return 0;
}
