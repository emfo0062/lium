/*

Main program for lab6

*/
#include <stdio.h>
#include <stdlib.h>
#include "resistance.h"


int main()
{
  int count, i;
  float totRes;
  float *array;
  char conn;
  printf("Ange spänningskälla i V:");
  printf("Ange koppling[S | P]:");
  if (scanf("%c", &conn)!=1) { printf ("error - it is not an char\n"); return -1; }
  printf("Antal komponenter:");
  if (scanf("%i", &count)!=1) { printf ("error - it is not an integer\n"); return -1; }
  array = (float*)  malloc(sizeof(float) * count);
  for (i=0; i < count; i++)
  {
    printf("Komponent %d i ohm:",i + 1);
    if (scanf("%f", &array[i])!=1) { printf ("error - it is not an float\n"); return -1; }
  }

  // Calculate values
  printf("Ersättningsresistans: %.2f ohm\n",calc_resistance(count,conn,array));
  printf("Effekt: %f W\n",1.78);
  printf("Ersättningsresistanser i E12-serien kopplade i serie:");
  free(array);
  return 0;
}
