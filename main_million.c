// This function will run with random inputs of 1 million numbers to test the Float addition program.
// Debajyoti Dash

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int FloatAdd(int, int);

int main(void)
{

  // float f1 = 2.0;
  // float f2 = 1.0;
  srand(time(NULL));
  int i;
  for (i=0; i<1000000;i++){
    
    int x = rand();
    int y = rand();

  int iresult = FloatAdd(x, y);
  // int iresult = FloatAdd(*(int *)&f1, *(int *)&f2);

  // printf("%08x\n", iresult);
  float fresult = (*(float *) &x) + (*(float *) &y);;
  // float fresult = f1+f2;

  printf("%08x + %08x --> %08x (should be %08x)\n", x, y, iresult,
   *(int *)&fresult);
  if (iresult != *(int *)&fresult){
    fprintf(stderr, "***ERROR***\n");
    fprintf(stderr, "***Calculation Performed***: %i \n", i); 
    return 0;
  }

  // printf("%08x + %08x --> %08x (should be %08x)\n", *(int *)&f1, *(int *)&f2, iresult,
  //   *(int *)&fresult);
 }
 fprintf(stderr, "***Calculation Performed***: %i \n", i); 
  return 0;
}
