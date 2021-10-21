/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:  Find roots of a quadratic equation
                      and find the ratio of the two roots
Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex_number {
    float real;
    float imag;
} complex;

float root1, root2;
complex croot;

int quadratic_solve(float a, float b, float c) {
    float d = b*b - 4*a*c;
    if (d > 0) {
        root1 = (-b + sqrt(d))/(2*a);
        root2 = (-b - sqrt(d))/(2*a);
    }
    else if (d == 0) {
        root1 = root2 = -b/(2*a);
    }
    else {
        croot.real = -b/(2*a);
        croot.imag = sqrt(-d)/(2*a);
    }
    return ((d >= 0) ? 1 : 0);
}

int main(void)
{
    float a, b, c, ratio;
    complex cratio;
    int flag;

    printf ("Input a, b, c: ");
    scanf ("%f %f %f", &a, &b, &c);

    flag = quadratic_solve(a, b, c);
    float r = croot.real;
    float i = croot.imag;

    if (flag) {
      ratio = root1/root2;
      printf ("\nRoot 1 = %f  Root 2 = %f\n", root1, root2);
      printf ("Ratio of the roots = %f\n\n", ratio);
    }
    else {
      cratio.real = (r*r - i*i)/(r*r + i*i);
      cratio.imag = (2*r*i)/(r*r + i*i);
      printf ("\nRoot 1 = %f + i(%f)  Root 2 = %f - i(%f)\n", r, i, r, i);
      printf ("Ratio of the roots = %f + i(%f)\n\n", cratio.real, cratio.imag);
    }

    return 0;
}
