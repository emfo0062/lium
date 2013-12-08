#include <stdio.h>

int add(int,int);

int main (void)
{
  char line[1024], *p, *e;
  int int_in;
  int sum = 0;
  fgets(line, sizeof(line), stdin);
  p = line;
  for (p = line; ; p = e)
  {
    int_in = (int) strtol(p, &e, 10);
    if (p == e)
      break;
    sum = add(sum,int_in);
  }
  printf("Result: %d\n",sum);
  return 0;
}
