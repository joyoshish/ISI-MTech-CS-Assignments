/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Jan 14 2021
Program Description:    
                    Spiral traversal of 2D matrix from
                    bottom-right corner

Acknowledgements:


----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

int row, col;

void spiralPrint (int mat[row][col], int i, int j, int m, int n) {
    int t;
    if (i > m || j > n)
        return;
    
    for (t = m; t >= i; t--)
        printf ("%d ", mat[t][n]);

    for (t = n-1; t >= j; t--)
        printf ("%d ", mat[i][t]);

    for (t = i+1; t <= m; t++)
        printf ("%d ", mat[t][i]);

    for (t = j+1; t < n; t++)
        printf ("%d ", mat[m][t]);

    spiralPrint (mat, i+1, j+1, m-1, n-1);
}

int main (void) {
    int i, j;
    scanf ("%d %d", &row, &col);
    int mat[row][col];
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf ("%d", &mat[i][j]);
        }
    }

    spiralPrint (mat, 0, 0, row-1, col-1);

    return 0;
}
