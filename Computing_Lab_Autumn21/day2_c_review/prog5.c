/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 21 2021
Program Description:    
                    Kaprekar number

Acknowledgements:


----------------------------------------------------*/


/**********************************
*	According to the problem description solved. Given is not the correct definition 
*	of Kaprekar number. eg. n = 4879	n*n = (238)(04641)   right 5 digits, left 3 digits
*										238 + 04641 = 4879
*
**********************************/



#include <stdio.h>
#include <stdlib.h>

int isKaprekar (int n) {
	int sqr = n*n, i, div = 1;
	int d = 0;
	while (sqr) {
		d++;
		sqr /= 10;
	}
	sqr = n*n;
	printf ("Sqr %d ", sqr);
	if (d % 2 == 0) {
		for (i = 0; i < d/2; i++) {
			div *= 10;
		}
		int left, right;
		left = sqr/div;
		right = sqr - left*div;
		printf ("left %d right %d", left, right);
		if (n == left + right)
			return 1;
		else
			return 0;
	}
	else {
		for (i = 0; i < d - (d/2); i++) {
			div *= 10;
		}
		int left, right;
		left = sqr/div;
		right = sqr - left*div;
		printf ("left %d right %d", left, right);
		if (n == left + right)
			return 1;
		else
			return 0;
	}
}

int main (void) {
	int n;
	printf ("Enter number: ");
	scanf ("%d", &n);
	
	int flag = isKaprekar(n);
	if (flag == 1)
		printf ("\nKaprekar number\n");
	else
		printf ("\nNot a Kaprekar number\n");
	
	return 0;
}
