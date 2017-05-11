#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int FloatAdd(int, int);

int main(void)
{

  // float f1 = 2.0;
  // float f2 = 1.0;
  //srand(time(NULL));
  //int i;
  //for (i=0; i<1000;i++){
    
    //int x = 321 - rand();
    //int y = rand();

  int x = 0xC0000000;
  int y = 0xC0000000;

  // ff8aa000 + 7f800000
  // 00000000 + ff800020
  // 7f800ab1 + 00000000
  // 00ff000f + 80ff0000

/*  1.0 + 2.0
    5.0 + 2.0
    0x40800000 + 0x4000001E
    0x41800000 + 0x40710000
    3.0 + (-1.0)
    0x4A00000F + 0xC0700000
    0x3F800000 + 0x3F800000
    0x4000000F + 0xC0000000  */

  /* Infinity - If the exponent field is all ones, 
  and the mantissa is all zeros, then this number is an infinity.*/
  // int y = 0x7F800000;
  // int y = 0xFF800000;

  /* NaN - These special quantities have an exponent field of 255 
  (all one bits) like infinity, but differ from the representation 
  of infinity in that the mantissa contains some one bits.*/
  // int y = 0x7FFFFFFF;
  // int y = 0xFFFFFFFF;
  // int y = 0xFF81ABD0;
  // int y = 0x7FAA12F9;
  // int y = 0x7F81A023;
  // int y = 0xffc00000;

  /* Zero - 0x80000000 is -0.0000000 and 0x00000000 is 0.0000000*/
  // int y = 0x80000000;
  // int y = 0x00000000;

  /* Normalized */
  // int y = 0xC0B40000;
  // int y = 0x43A4B200;

  /* De-Normalized */
  // int y = 0x80280000; 


  int iresult = FloatAdd(x, y);
  // int iresult = FloatAdd(*(int *)&f1, *(int *)&f2);

  // printf("%08x\n", iresult);
  float fresult = (*(float *) &x) + (*(float *) &y);;
  // float fresult = f1+f2;

  printf("%08x + %08x --> %08x (should be %08x)\n", x, y, iresult,
   *(int *)&fresult);
  if (iresult != *(int *)&fresult){
    fprintf(stderr, "***ERROR***\n");
    //fprintf(stderr, "***Calculation Performed***: %i \n", i); 
    return 0;
  }

  // printf("%08x + %08x --> %08x (should be %08x)\n", *(int *)&f1, *(int *)&f2, iresult,
  //   *(int *)&fresult);
 //}
 //fprintf(stderr, "***Calculation Performed***: %i \n", i); 
  return 0;
}
