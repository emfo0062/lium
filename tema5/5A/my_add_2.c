#include <stdio.h>

int main(int argc,char* argv[])
{
  int int1, int2;
  if (argc =! 3)
  {
    printf("Usage plus_2 x y\n");
    return 127;
  }
  if (sscanf (argv[1], "%i", &int1)!=1) { printf ("error - first argument is not an integer\n"); return 2; }
  if (sscanf (argv[2], "%i", &int2)!=1) { printf ("error - second argument is not an integer\n"); return 2; }

  printf("Result: %d + %d = %d\n",int1,int2,int1+int2);
  return 0; 
}
