/****************************************
* Libresistance.c
*
* Author:Petter Lerenius
*
*****************************************/
#include <stdio.h>

float serial_resistors(int count, float *array);
float parallel_resistors(int count, float *array);

// Calculate total resistance for a number of
// parallel or serial connected resistors
float calc_resistance(int count, char conn, float *array)
{
  float tot_resistance = -1;
  if (array == 0)
  {
    printf("array is NULL!\n");
    return -1;
  }

  switch(conn)
  {
    case 'P':
    case 'p':
      tot_resistance = parallel_resistors(count, array);
      break;
    case 'S':
    case 's':
      tot_resistance = serial_resistors(count, array);
      break;
    default:
      printf("Unknown connection letter! [P,p,S,s]\n");
      return -1;
      break;
  }
  return tot_resistance;
}

// R1+R2
float serial_resistors(int count, float *array)
{
  int i;
  float totRes=0;
  for (i = 0; i < count; i++)
  {
    totRes += array[i];
  }
  return totRes;
}

//1/R1+1/R2
float parallel_resistors(int count, float *array)
{
  int i;
  float totRes=0;
  for (i = 0; i < count; i++)
  {
    if (array[i] == 0) { return 0; }
    totRes += 1.0/array[i];
  }
  return 1.0/totRes;
}
