// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter20_1
// File chapter20_1.c

/* This program demonstrates the math functions from the C math.h library,
 * so that you can get your homework right thanks to some quick-and-easy programming. */

#include <stdio.h>
#include <string.h>
#include <math.h>
#define PY 3.14159

int main(void)
{
  // "const double PY = 3.141519" didn't work. While #define PY 3.14159 worked well.
  printf("It's time to do your math homework!\n");

  printf("Section 1: Square Roots\n");
  printf("The square root of 49.0 is %.1f\n",sqrt(49.0));
  printf("The square root of 149.0 is %.1f\n",sqrt(149.0));
  printf("The square root of .149 is %.2f\n",sqrt(.149));

  printf("\n\nSection 2: Powers\n");
  printf("4 raised to the 3rd power is %.1f\n",pow(4.0, 3.0));
  printf("7 raised to the 5rd power is %.1f\n",pow(7.0, 5.0));
  printf("34 raised to the 1/2 power is %.1f\n",pow(34.0, .5));

  printf("\n\nSection 3: Trigonometry\n");
  printf("The cosine of a 60-degree angle is %.3f\n",cos((60 * (PY / 180.0))));
  printf("The sine of a 90-degree angle is %.3f\n",sin((90 * (PY / 180.0))));
  printf("The tangent of a 75-degree angle is %.3f\n",tan((75 * (PY / 180.0))));
  printf("The arc cosine of a 45-degree angle is %.3f\n",acos((45 * (PY / 180.0))));
  printf("The arc sine of a 30-degree angle is %.3f\n",asin((30 * (PY / 180.0))));
  printf("The arc tangent of a 15-degree angle is %.3f\n",atan((15 * (PY / 180.0))));

  printf("\nSection 4: Log functions\n");
  printf("e raised to 2 is %.3f\n",exp(2));
  printf("The natural log of 5 is %.3f\n",log(5));
  printf("The base-10 log of 5 is %.3f\n",log10(5));

  return 0;
}
