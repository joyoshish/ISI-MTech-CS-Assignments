/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 21 2021
Program Description:    
                    Logical conditions

Acknowledgements:


----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isIntOrFloat (float x, float y) {
	int z = ceil(x+y);
	if (x+y == z)
		return 1;
	else
		return 0;
}

int lieBetween (int m, float x, float y) {
	float fm = (float)m;
	if (m - x > 0 && y - m > 0)
		return 1;
	else if (m - y > 0 && x - m > 0)
		return 1;
	else
		return 0;
}

int intPart (float x) {
	return floor(x);
}

int condition4 (float x) {
	int dec = (int)x;
	float frac = x - dec;
	
	if (dec >= 3 && frac < 0.3 && x > 0.0)
		return 1;
	else
		return 0;
}

int parity (int m) {
	if (m % 2 == 0)
		return 1;
	else 
		return 0;
}

int perfectSqr (int m) {
	if (ceil((double)sqrt(m)) == floor((double)sqrt(m))) 
    	return 1;
    else 
    	return 0;
}



int main (void) {
	
	signed int m, n;
	float x, y;
	
	printf ("Enter m, n, x, y: ");
	scanf ("%d %d %f %f", &m, &n, &x, &y);
	
	printf ("\nx+y is an integer : ");
	if (isIntOrFloat(x, y) == 1)
		printf ("True\n");
	else
		printf ("False\n");
		
		
	printf ("\nm lies strictly between x and y : ");
	if (lieBetween(m, x, y) == 1)
		printf ("True\n");
	else
		printf ("False\n");
		
		
	printf ("\nm equals integer part of x : ");
	if (m == intPart(x))
		printf ("True\n");
	else
		printf ("False\n");
		
		
	printf ("\nx is +ve with decimal part >= 3 and fractional part < 0.3 : ");
	if (condition4(x) ==  1)
		printf ("True\n");
	else
		printf ("False\n");
		
		
	printf ("\nm and n have same parity : ");
	if (parity(m) == parity(n))
		printf ("True\n");
	else
		printf ("False\n");
		
		
	printf ("\nm is perfect square : ");
	if (perfectSqr(m) == 1)
		printf ("True\n");
	else
		printf ("False\n");
	
	
	
	return 0;
}
