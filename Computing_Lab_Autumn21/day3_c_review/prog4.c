/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:  
                    Logical conditions on COmplex Numbers

Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct Complex{
	double real;
	double imag;
} complex;

bool isEqual(double x, double y)
{
   return x == y;
}

int main (void) {
	complex x, y, z, w;
	double realx, realy, imagy, imagx;
	printf ("Enter real part of x : ");
	scanf ("%lf", &realx);
	printf ("Enter imaginary part of x : ");
	scanf ("%lf", &imagx);
	printf ("Enter real part of y : ");
	scanf ("%lf", &realy);
	printf ("Enter imaginary part of y : ");
	scanf ("%lf", &imagy);
	
	x.real = realx;
	x.imag = imagx;
	y.real = realy;
	y.imag = imagy;
	
	z.real = x.real + y.real;
	z.imag = x.imag + y.imag;
	
	double zero = 0.0;
	
	if (isEqual(z.real, zero))
		printf ("\nx+y pure imaginary\n");
	else
		printf ("\nx+y not pure imaginary\n");
		
	w.real = x.real - y.real;
	w.imag = x.imag - y.imag;
		
	if (isEqual(w.imag, zero))
		printf ("\nx-y real\n");
	else
		printf ("\nx-y not real\n");
		
	
	if (isEqual(x.real, y.real) && (isEqual(x.imag, -(y.imag)) || isEqual(-(x.imag), y.imag)))
		printf ("\nx, y are complex conjugate\n");
	else
		printf ("\nx, y are not complex conjugate\n");
	
	
	return 0;
}
