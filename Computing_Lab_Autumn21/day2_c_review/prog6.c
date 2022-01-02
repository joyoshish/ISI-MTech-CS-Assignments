/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 21 2021
Program Description:    
                    Bitwise operations

Acknowledgements:


----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

# define bool int


#define INT_SIZE sizeof(int)      
#define INT_BITS INT_SIZE * 8 - 1 


int Parity(int n)
{
	return (n & 1);
}

unsigned int Div_by_8(int n)
{
    return (((n >> 3) << 3) == n);
}

unsigned int expo2 (int n)
{
	unsigned int i, res = 1;
	for (i = 0; i < n; i++) {
		res = res << 1;
	}
	return res;
}

int rotateLeft(int num, unsigned int rotation)
{
    int DROPPED_MSB;
    rotation %= INT_BITS;

    while(rotation--)
    {
        DROPPED_MSB = (num >> INT_BITS) & 1; 
        num = (num << 1) | DROPPED_MSB;
    }

    return num;
}

int rotateRight(int num, unsigned int rotation)
{
    int DROPPED_LSB;
    rotation %= INT_BITS;

    while(rotation--)
    {
        DROPPED_LSB = num & 1;
        num = (num >> 1) & (~(1 << INT_BITS));
        num = num | (DROPPED_LSB << INT_BITS);
    }

    return num;
}




int main (void) {
	unsigned int m, n, k;
	printf ("Enter n: ");
	scanf ("%ud", &n);
	printf ("Enter k: ");
	scanf ("%ud", &k);
	
	
	m = Parity(n);
	printf ("\nParity of n\n");
	printf ("m = %d\n", m);
	
	m = Div_by_8(n);
	printf ("\nDivisibility by 8\n");
	printf ("m = %u\n", m);
	
	m = expo2(n);
	printf ("\nm = 2^n\n");
	printf ("m = %u\n", m);
	
	m = rotateLeft(n, k);
	printf ("\nLeft rotation\n");
	printf ("m = %u\n", m);
	
	m = rotateRight(n, k);
	printf ("\nRight rotation\n");
	printf ("m = %u\n", m);	

	
	return 0;
}
