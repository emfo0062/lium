#include <stdio.h>

int main (void)
{
  char line[1024], *p, *e;
  long int_in;
  long sum = 0;
  fgets(line, sizeof(line), stdin);
  p = line;
  for (p = line; ; p = e)
  {
    int_in = strtol(p, &e, 10);
    if (p == e)
        break;
    printf("%3ld + %ld = %3ld\n", sum, int_in, int_in + sum);
    sum += int_in;
  }
  printf("Result: %ld\n",sum);
  return 0;
}
