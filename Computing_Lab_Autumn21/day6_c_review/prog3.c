/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    Macro functions

Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMPLY(x, y) ((!x) || y)

#define SWAP(x,y) do {\
    unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1];\
    memcpy(swap_temp,&y,sizeof(x));\
    memcpy(&y,&x,       sizeof(x));\
    memcpy(&x,swap_temp,sizeof(x));\
} while(0)

#define MIN(x, y) ((x)<(y))?(x):(y)

#define MAX(x, y) ((x)>(y))?(x):(y)

#define INF_PRINT(x) while(1) printf("%d\n", x);

#define LSB(x) ((x) || 1)

int main (void) {
    
    int x = 3, y = 5;
    printf ("\nx implies y: %d\n", IMPLY(x, y));
    
    SWAP(x, y);
    printf ("\nAfter swapping: x: %d y: %d\n", x, y);

    printf ("\nMinimum: %d\n", MIN(x, y));

    printf ("\nMaximum: %d\n", MAX(x, y));

    //INF_PRINT(x);

    printf ("\nLSB of x: %d\n", LSB(x));

    return 0;
}