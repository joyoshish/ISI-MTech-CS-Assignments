/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:    Whether there exists any SPECIAL
                        number for a given value of
                        `number of digits` n

        Existence of SPECIAL numbers:
                        Say digits are d1, d2,..., dn
                        For existence of a SPECIAL number,

                        d1 + d2 + ... + dn + (d1 * d2 * ... * dn) = (10^(n-1))*d1 + (10^(n-2))*d2 + ... + dn      (i)

                        this equation has to have a solution. Ultimately this implies the condition that

                        [999...up to (n-1) digits]/[9^(n-2)] has to be <= 9. This seems to happen only when n = 2 i.e.

                        number of digits = 2. In this case, the right digit d2 comes to be 9 for the equation (i) to satisfy.
                        
                        SPECIAL numbers of 2 digits are: 19, 29, 39, 49, 59, 69, 79, 89, 99

Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nd;

    printf ("Input number of digits: ");
    scanf ("%d", &nd);

    if (nd == 2)
      printf ("\nExists!\n");
    else
      printf ("\nDoes not exist!\n");

    return 0;
}
