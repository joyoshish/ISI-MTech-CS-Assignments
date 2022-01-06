/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    Write a header file for the ease of dynamic memory allocation,
                    deallocation and reallocation for one-dimensional and
                    multi-dimensional arrays. Use it to write a program for
                    swapping the contents of two files without using any
                    additional file.

Acknowledgements:

----------------------------------------------------*/


#include "utility.h"

int main(void)
{
    FILE *fp1, *fp2;
    char *filename1, *filename2, *file1, *file2, c;
    int i;
    
    i = 0;
    filename1 = single_char_array(100);
    file1 = single_char_array(100000);
    printf("Enter name of file 1:\n");
    scanf("%s", filename1);
    fp1 = fopen(filename1, "r");
    if (fp1 == NULL){
        printf("Enter the valid name\n");
        return 0;
    }
    while(1){
        c = fgetc(fp1);
        file1[i] = c;
        if (c == EOF){
            break;
        }
        i++;
    }
    file1[i] = '\0';

    i =0;
    filename2 = single_char_array(100);
    file2 = single_char_array(100000);
    printf("Enter name of file 2:\n");
    scanf("%s", filename2);
    fp2 = fopen(filename2, "r");
    if (fp2 == NULL){
        printf("Enter the valid name\n");
        return 0;
    }
    while(1){
        c = fgetc(fp2);
        file2[i] = c;
        if (c == EOF){
            break;
        }
        i++;
    }
    file2[i] = '\0';

    fclose(fp1);
    fclose(fp2);

    fp1 = fopen(filename1, "w");
    fp2 = fopen(filename2, "w");

    fputs(file1, fp2);
    fputs(file2, fp1);

    fclose(fp2);
    fclose(fp1);
    return 0;
}