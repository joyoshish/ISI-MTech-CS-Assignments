/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    Compute Binomial Coeff. using recursive formula
                    C(n, r) = C(n-1, r) + C(n-1, r-1)

Acknowledgements:

----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int C(int n , int r){
    if (n < r) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (r == 1) {
        return n;
    }
    return C(n-1, r) + C(n-1, r-1);
}

int main (void) {
    int n,r;
    printf ("Enter n, r: ");
	scanf("%d %d",&n,&r);

	printf("%dC%d = %d\n", n, r, C(n,r));


    return 0;
}