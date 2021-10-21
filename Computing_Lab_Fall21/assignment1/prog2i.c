/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:    Checking if a number is SPECIAL (sum of `the
                        digits` and `the product of its digits` equals
                        to the original number)
Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

int isSpecial(int n, int *arr, int size) {
    int i, sum = 0, product = 1;
    for (i = 0; i < size; i++)
        sum += arr[i];
    for (i = 0; i < size; i++)
        product *= arr[i];
    sum = sum + product;
    if (sum == n)
        return 1;
    else
        return 0;
}

int main(void)
{
    int k, n, no, nd = 0, flag;

    printf ("Input number: ");
    scanf ("%d", &no);
    n = no;

    int *digits;
    digits = (int*)malloc(1*sizeof(int));

    while(n != 0) {
        k = n%10;
        nd++;
        digits = realloc(digits, nd*sizeof(int));
        digits[nd-1] = k;
        n = n/10;
    }

    flag = isSpecial(no, digits, nd);

    (flag == 1) ? printf("Special!\n") : printf ("Not special!\n");

    return 0;
}
