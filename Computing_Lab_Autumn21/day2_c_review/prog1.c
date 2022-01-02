/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 21 2021
Program Description:    
                    Checking friendly numbers

Acknowledgements:


----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

int sumOfDivisors(int n) {
    int i, sum = 1;
    for (i = 2; i*i <= n; i++) {
        int curr_sum = 1;
        int curr_term = 1;
        while (n%i == 0) {
            n /= i;
            curr_term *= i;
            curr_sum += curr_term;
        }
        sum *= curr_sum;
    }
    if (n >= 2) 
        sum *= (n+1);
    return sum;
}


int main (void) {
    int n1, n2;
    printf ("\nEnter two integers: ");
    scanf ("%d %d", &n1, &n2);

    float abundancy1, abundancy2;
    abundancy1 = ((float)sumOfDivisors(n1))/n1;
    abundancy2 = ((float)sumOfDivisors(n2))/n2;

    printf ("%f %f\n", abundancy1, abundancy2);

    (abundancy1 == abundancy2) ? printf ("\nFriendly\n") : printf ("\nNot Friendly\n");

    return 0;
}