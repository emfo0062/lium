#include <stdio.h>

int main (void)
{
  char char_in[10];
  int int_in, result;
  int sum = 0;
  while (scanf("%s",&char_in[0]))
  {
    if (char_in[0] == '\n') { printf("Result: %d\n",sum);return 0; }
    sscanf(char_in,"%d",&int_in);
    printf("%3d + %d = %3d\n", sum, int_in, int_in + sum);
    sum += int_in;
  }
}
