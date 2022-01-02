/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 21 2021
Program Description:    
                    Pattern printing

Acknowledgements:


----------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int n, i, j, k;
	printf ("Enter number of rows: ");
	scanf ("%d", &n);
	
	i = 1;
	int sp = (2*n - 1)/2;	//initial number of left spaces
	int midsp = 1; 			//initial number of midspaces at row 2
	
	while (i <= n) {
		if (i == 1) {	//if first row
			for (j = 0; j < sp; j++)
				printf (" ");
			sp--;
			printf ("*\n");
		}
		else {			//if any other row
			for (j = 0; j < sp; j++)
				printf (" ");
			sp--;
			printf ("*");
			for (j = 0; j < midsp; j++)
				printf (" ");
			midsp += 2;
			printf ("*\n");
		}
		
		i++;
	}
	
	return 0;
}
