/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    What f computes?

Acknowledgements:

----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int f(int n) {
	int s = 0;
	while(n--) s += 1 + f(n);
	return s;
}

int fun(int n) {
    int ret;
	if(n == 0) {
        return 0;
    }
	else
        ret = 2*fun(n-1) + 1;
    printf ("%d %d \n", n, ret);
    return ret;
}

int main (void) {
    int n;
    printf ("\nEnter a number: ");
    scanf ("%d", &n);
	printf ("f(%d) = %d\n", n, f(n));
    printf ("f(%d) = %d\n", n, fun(n));
    printf ("\nf computes the recursion f(n) = 2f(n-1) + 1 with f(0) = 0\n");

    return 0;
}