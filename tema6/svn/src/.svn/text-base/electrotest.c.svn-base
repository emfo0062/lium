/*

Main program for lab6

*/
#include <stdio.h>
#include <stdlib.h>
#include <resistance.h>
#include <component.h>
#include <power.h>

int main()
{
  int count, i;
  float totRes;
  float volt=2.0;
  float power;
  float *array;
  char conn;
  float resistors[3];
  float *fp=&resistors[0];
  int antal;


  printf("Ange koppling[S | P]: ");
  if (scanf("%c", &conn)!=1) { printf ("Error - Inmatat värde är inte en char\n"); return -1; }
  printf("Antal komponenter: ");
  if (scanf("%i", &count)!=1) { printf ("Error - Inmatat värde är inte en integer\n"); return -1; }
  array = (float*)  malloc(sizeof(float) * count);
  for (i=0; i < count; i++)
  {
    printf("Komponent %d i ohm: ",i + 1);
    if (scanf("%f", &array[i])!=1) { printf ("Error - Inmatat värde är inte en float\n"); return -1; }
  }
  // Calculate values
  totRes = calc_resistance(count,conn,array);
  if (totRes == -1) {printf ("Error - Misslyckades med att räkna ut ersättningsresistans\n"); return -1;}
  printf("Ersättningsresistans: %.2f ohm\n",totRes);

  printf("Ange spänningskälla i V: ");
  if (scanf("%f", &volt)!=1){ printf("Error - Inmatat värde är inte en float\n"); return -1;}
  power = calc_power_r(volt, totRes);
  printf("Effekt: %.2f W\n", power);
  printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
  for (antal = e_resistance(totRes, &resistors[0]); antal>0; antal--){
    printf("%1.0f", *fp++);
    if (antal>1)
      printf(", ");
  }
  printf("\n");

  free(array);
  return 0;
}
