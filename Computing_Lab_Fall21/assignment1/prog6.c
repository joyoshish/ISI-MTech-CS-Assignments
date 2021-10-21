/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:  
                    Suppose there are two separate files each of which contains a
                    sufficiently large integer value. Write a program that will take
                    those two filenames as command line arguments and return
                    the result of their summation.
                    Note: An efficient implementation will not depend on the
                    primary memory of the system.

Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int result[255];
static int count = 0;

int getNum(FILE *fp, int pos) 
{
    int i = 0, ret;
    char ch;
    while (i <= pos) {
        ch = fgetc(fp);
        i++;
    }
    ret = ch - '0';
    rewind(fp);
    return ret;
}

void storeResult(int d) {
    result[count++] = d;
}

int main (int argc, char **argv)
{
    int l1 = 0, l2 = 0, sum = 0, difference, carry = 0, i, j, num1, num2;
    char c;
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    for (c = fgetc(file1); c != EOF; c = fgetc(file1))
        l1++;
    rewind (file1);
    for (c = fgetc(file2); c != EOF; c = fgetc(file2))
        l2++;
    rewind (file2);

    if (l1 > l2) {
        difference = l1 - l2;
        for (i = l2-1; i >= 0; i--) {
            num1 = getNum(file2, i);
            num2 = getNum(file1, i+difference);
            sum = num1 + num2 + carry;
            storeResult(sum%10);
            carry = sum/10;
        }
        for (i = l1-l2-1; i >= 0; i--) {
            sum = getNum(file1, i) + carry;
            storeResult(sum%10);
            carry = sum/10;
        }
        if (carry) {
            storeResult(carry);
        }
    }
    else {
        difference = l2 - l1;
        for (i = l1-1; i >= 0; i--) {
            num1 = getNum(file1, i);
            num2 = getNum(file2, i+difference);
            sum = num1 + num2 + carry;
            storeResult(sum%10);
            carry = sum/10;
        }
        for (i = l2-l1-1; i >= 0; i--) {
            sum = getNum(file2, i) + carry;
            storeResult(sum%10);
            carry = sum/10;
        }
        if (carry) {
            storeResult(carry);
        }
    }
    

    printf ("Sum: ");
    for (i = count-1; i >= 0; i--)
      printf ("%d", result[i]);
    printf ("\n");

    fclose(file1);
    fclose(file2);

    return 0;
}