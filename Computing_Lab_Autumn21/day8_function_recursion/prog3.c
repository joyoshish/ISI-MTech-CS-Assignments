/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    Write a program that takes a positive integer n ≤ 5, and a
                    non-negative integer k ≤ 100 as command-line arguments,
                    and computes the total number of cells reachable from any
                    starting cell within an infinite, n-dimensional grid in 
                    k steps or less.

					f(n, k) = f(n-1, k) + [sumover(i=0 to k-1)] 2*f(n-1, i)

Acknowledgements:

----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int f(int n, int k) {
	if(n == 1)
		return 2*k + 1;
	if(k == 0)
		return 1;
	else {
		int i, sum = 0;
		for(i = k-1; i >= 0; i--)
			sum += 2*f(n-1, i);
		return sum + f(n-1, k);
	}
}

int main (int argc, char *argv[]) {
    char *n = argv[1], *k = argv[2];
    printf("#Cells reachable: %d\n", f(atoi(n), atoi(k)));
    return 0;
}