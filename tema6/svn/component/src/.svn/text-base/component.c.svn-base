#include <stdio.h>
#define E12_MAX 1000000
#define E12_MIN 10

const float E12[]={10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82, 100};

int find_E12_component(float value, float *res_pointer)
{
  const float *fp = &E12[0];
  int powerOfTen=1;
  int hittad = 0;

  *res_pointer=0;
  
  if (value > E12_MIN/2){
    hittad = 1;
    if (value > E12_MAX)
      *res_pointer = E12_MAX;
    else{
      while (value > 100){
	value /= 10;
	powerOfTen *= 10;
      }
      while (value > *++fp);
      *res_pointer = *(fp-1) * powerOfTen;
    }
  }
  return hittad;
}

int e_resistance(float orig_resistance, float *res_array)
{
  int i, count=0;
  float epsilon = 0.001;

  for (i=3; i>0; i--){
    if (orig_resistance  < 56 )
      epsilon = 0.1;
    count += find_E12_component(orig_resistance*(1+epsilon), res_array);
    orig_resistance -= *res_array++;
    epsilon *=10;
    }

  return count;
}
