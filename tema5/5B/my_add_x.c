#include <stdio.h>

int main (void)
{
  int int_in, result;
  int sum = 0;
  char in[100];
  fgets(in,sizeof in,stdin);
  while (sscanf(in,"%d",&int_in))
  {
    printf("%3d + %d = %3d\n", sum, int_in, int_in + sum);
    sum += int_in;
  }
}
