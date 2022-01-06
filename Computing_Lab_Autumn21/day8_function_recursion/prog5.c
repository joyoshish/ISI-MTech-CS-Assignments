/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    Tower of Hanoi

Acknowledgements:

----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int TOH (int n, char src, char aux, char dest) {
    int steps = 1;
    if (n == 0) {
        return 0;
    }
    else {
        steps += TOH(n-1, src, dest, aux) ;
        printf ("\nMove disk from %c to %c\n", src, dest);
        steps += TOH(n-1, aux, src, dest);
    }
    return steps;
}

int main (void) {
    int n, steps;
    printf("Enter number of disks: ");
    scanf ("%d",  &n);
    steps = TOH (n, 'A', 'B','C');
    printf ("\nNumber of steps = %d\n", steps);

    return 0;
}
