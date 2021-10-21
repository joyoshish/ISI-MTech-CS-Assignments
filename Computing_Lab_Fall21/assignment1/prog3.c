/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:  
                    Write a program to verify whether an input matrix is square or
                    not. If it is not a square matrix, print NOT SQUARE.
                    Otherwise, further check whether it is singular (determinant is
                    0) or unimodular (determinant is 1). Accordingly, print
                    SQUARE - SINGULAR or SQUARE - UNIMODULAR, otherwise
                    print SQUARE - OTHER.

Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void swap (float *a, float *b) {
    float c;
    c = *a;
    *a = *b;
    *b = c;
}


float findDet (int m, float matrix[m][m]) {
    float ref[m][m];
    int i, j, flag = 0;
    for (i = 0; i < m; i++) {   //checking if first row is all zeros
        if (matrix[0][i] == 0)
            flag = 1;
        else {
            flag = 0;
            break;
        }
    }
    if (flag == 1)  
        return 0;
    
    for (i = 0; i < m; i++) {   //checking if first column is all zeros
        if (matrix[i][0] == 0)
            flag = 1;
        else {
            flag = 0;
            break;
        }
    }
    //printf ("\nflag %d\n", flag);
    if (flag == 1)
        return 0;

    // finding first non zero element in 1st column
    int find = 0;
    for (i = 0; i < m; i++) {
        if (matrix[i][0] != 0) {
            find = i;
            //printf ("\nnz = %d\n\n", find);
            break;
        }
    }

    // swap the rows (0th and found one)
    int swapped = 0;
    if (find != 0) {
        for (i = 0; i < m; i++) {
            swap (&matrix[0][i], &matrix[find][i]);
        }
        swapped = 1;        //if swapped rows, negate the determinant value
    }

    for (i = 0; i < m; i++) //copying first row of matrix to ref matrix
        ref[0][i] = matrix[0][i];

    
    int count = m-1;    //number of times to go through the loop is (m-1) + (m-2) + ... + 2 + 1
    int l = 2;
    int k = 0;
    int col = 0;
    int row = 0;

    //converting to ref
    for (j = 1; j <= m-1; j++) {
        //printf ("\nj = %d\n", j);
        for (; l <= m; l++) {
            //printf ("\nl = %d\n", l);
            //printf ("\n\n matrix[l-1][col] = %f  matrix[row][col] = %f\n\n", matrix[l-1][col], matrix[row][col]);

            if (matrix[row][col] == 0) {
                //printf ("\nProgram limitation! \n");
                //exit(0);
                for (i = 0; i < m; i++)
                    swap (&matrix[row][i], &matrix[l-1][i]);
                swapped = (swapped + 1)%2;
            }
            else {
                float scale = (-1)*(matrix[l-1][col] / matrix[row][col]);
                //printf ("\nscale %f\n", scale);
                for (i = 0; i < m; i++) {
                    matrix[l-1][i] = matrix[l-1][i] + matrix[row][i] * scale;
                }
            }
        }
        row++;
        col++;
        k++;
        l = 2 + k;
    }


    //print ref matrix
    printf ("\n\nMatrix in Row Echelon form:\n\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < m ;j++) {
            printf ("\t%.2f ", matrix[i][j]);
        }
        printf ("\n");
    }

    //finding determinant
    float det = 1;
    for (j = 0; j < m; j++) {
        det *= matrix[j][j]; 
    }
    if (swapped == 1)
        det = (-1)*det;
    printf ("\nDeterminant value is %f\n", det);
    return det;




}

int main(void)
{
    int m, n, i, j, flag;
    
    printf ("\nEnter number of rows: ");
    scanf ("%d", &m);
    printf ("\nEnter number of columns: ");
    scanf ("%d", &n);
    
    float matrix[m][n];

    for (i = 0; i < m; i++) {
        printf ("\nEnter row %d: ", i+1);
        for (j = 0; j < n; j++) {
            scanf ("%f", &matrix[i][j]);
        }
    }

    printf ("\nMatrix: \n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf ("\t%.2f ", matrix[i][j]);
        }
        printf ("\n");
    }

    if (m != n) {
        printf ("\nNOT SQUARE\n");
    }
    else {
        flag = findDet(m, matrix);
        if (flag == 0.0)
            printf ("\nSQUARE - SINGULAR\n");
        else if (flag == 1.0)
            printf ("\nSQUARE - UNIMODULAR\n");
        else 
            printf ("\nSQUARE - OTHER\n");
    }



    return 0;
}