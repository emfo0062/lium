#include <stdlib.h>
#include <stdio.h>
#include <component.h>

// int e_resistance(float orig_resistance, float *res_array);

main(int argc, char *argv[])
{
  float resistors[3];
  float *fp=&resistors[0], e_total;
  int i, count;

  if (argc < 2){
    printf ("\tUsage: \"prog orig_resistance\"\n");
    return;
    }

  printf("\tOriginal resistance: %1.0f\n", atof(argv[1]));
  printf("\tErsättningsresistorer: ");
  for (count = e_resistance(atof(argv[1]), &resistors[0]); count>0; count--){
    printf("%1.0f", *fp++);
    if (count>1)
      printf(", ");
  }
  printf("\n");


  // For further debug purposes
  if (argc > 2){
    for (i=atoi(argv[1]);i<atoi(argv[2]); i++){
      printf("%d\t  ", i);
      fp=&resistors[0];
      e_total = 0;
      for (count = e_resistance(i, &resistors[0]); count>0; count--){
	e_total = e_total + *fp;
	printf("%1.0f", *fp++);
	if (count>1)
	  printf(", ");
      }  
      printf("     %1.2f\n", 100*(i-e_total)/i);
    }
  }
}
