// Test libresistance library
#include <stdio.h>

#include "resistance.h"

int main(void)
{
  int res=0;
  res += testSerial();
  res += testParallel();
  return res;
}

int testSerial()
{
  float resistors[] = {1,2,3};
  float totRes = calc_resistance(3,'S',resistors);
  printf("Serial = %f\n",totRes);
  return (totRes != 6.0);
}

int testParallel()
{
  float resistors[] = {1,1,1};
  float totRes = calc_resistance(3,'P',resistors);
  printf("Parallel = %f\n",totRes);

  float resistors2[] = {3,3,3};
  totRes = calc_resistance(3,'P',resistors2);
  printf("Parallel = %f\n",totRes);

  return 0;
}
