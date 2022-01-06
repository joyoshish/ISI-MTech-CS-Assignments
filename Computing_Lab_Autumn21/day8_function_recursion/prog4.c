/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    Recursive and interative function for G(n) = 

                            0 if n = 0
                            1 if n = 1
                            2 if n = 2
                            G(n − 1) + G(n − 2) + G(n − 3) if n ≥ 3

Acknowledgements:

----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(type, n) (type *)malloc(sizeof(type)*n)

int recursiveG(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else {
        return recursiveG(n-1) + recursiveG(n-2) + recursiveG(n-3);
    }
}


int iterativeG(int n) {
    int *G;
    G = MALLOC(int, n+1);

    G[0] = 0;
    if (n >= 1)
        G[1] = 1;
    if (n >= 2)
        G[2] = 2;
    int i;
    for (i=3;i<=n;i++){
        G[i] = G[i-3] + G[i-1] + G[i-2];
    }
    return G[n];
}

int main (void) {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Recursive  G(%d) : %d\n", n, recursiveG(n));    
    printf("Iterative  G(%d) : %d\n", n, iterativeG(n));    

    return 0;
}