/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:  
			Pointer to structure pointers                    

Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Test{
	int x;
}test;

int main (void) {
	int n;
	test T;
	test* ptr1 = &T;
	test** ptr2 = &ptr1;
	
	printf ("Enter value to assign: ");
	scanf ("%d", &n);
	(*(*ptr2)).x = n;
	
	printf ("Value in structure: %d\n", T.x);
	
	return 0;
}
