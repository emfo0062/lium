//************************************
// Test functions for testing the 
// libresistance library
//
// Author: Petter Lerenius
//************************************

#include <stdio.h>

#include "resistance.h"

int main(void)
{
  int res=0;
  res += testSerial();
  res += testParallel();
  res += testNull();

  printf("=============================\nResistance test was: ");
  if (res == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAILED\n");
  }
  return res; 
}

int testSerial()
{
  float resistors[] = {1,2,3};
  float resistors0[] = {0,1,10,100,1000};

  // Test big 'S'
  float totRes = calc_resistance(3,'S',resistors);
  printf("Serial   = %7.2f\n",totRes);
  if (totRes != 6.0) { return 1; }

  // Test small 's'
  totRes = calc_resistance(3,'s',resistors);
  printf("Serial   = %7.2f\n",totRes);
  if (totRes != 6.0) { return 1; }

  // Test using 0 ohm
  totRes = calc_resistance(5,'s',resistors0);
  printf("Serial   = %7.2f\n",totRes);
  if (totRes != 1111.0) { return 1; }

  return 0;
}

int testParallel()
{
  float resistors3[] = {3,3,3};
  float resistors5[] = {100,100,100,100,100};
  float resistors0[] = {0,1,10,100,1000};

  // Test using big 'S'
  float totRes = calc_resistance(3,'P',resistors3);
  printf("Parallel = %7.2f\n",totRes);
  if (totRes != 1.0) { return 1; }

  // Test using small 'p'
  totRes = calc_resistance(3,'p',resistors3);
  printf("Parallel = %7.2f\n",totRes);
  if (totRes != 1.0) { return 1; }

  // Test using 5 resistors
  totRes = calc_resistance(5,'P',resistors5);
  printf("Parallel = %7.2f\n",totRes);
  if (totRes != 20.0) { return 1; }

  // Test with a 0ohm
  totRes = calc_resistance(5,'P',resistors0);
  printf("Parallel = %7.2f\n",totRes);
  if (totRes != 0) { return 1; }


  return 0;
}

int testNull()
{
  float totRes = calc_resistance(3,'P',NULL);
  if (totRes != -1) { return 1; }

  return 0;
}
