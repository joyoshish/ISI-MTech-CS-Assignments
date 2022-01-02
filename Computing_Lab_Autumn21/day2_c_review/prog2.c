/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 21 2021
Program Description:    
			Trailing zeros in n!

Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

int countZeros (int n) {
    int count = 0;

    do {
        n /= 5;
        count += n;
    } while (n >= 5);
    
    return count;
}

int main (void) {
    int n, i, temp, count = 0;
    printf ("\nEnter number: ");
    scanf ("%d", &n);

    printf ("\nNumber of trailing zeros in %d! = %d\n", n, countZeros(n));

    return 0;
}
