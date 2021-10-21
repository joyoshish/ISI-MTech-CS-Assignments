/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:  
                    You have to write a program that reads its own source file
                    and prints the lines in that file in
                    lexicographically sorted order.

Acknowledgements:

----------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
    FILE *fp = fopen(__FILE__,"r");;
    char ch, prog[5][5];
    int noOfLines = 0;
    char data[100];

    while ((ch = fgetc(fp)) != EOF) {
        if (ch  == '\n')
            noOfLines++;
    }
    noOfLines++;
    rewind(fp);

    long ptr[noOfLines];
    long i = 0, j = 0, diff = 0, count = 0;
    ptr[0] = 0;     // contains position of the 1st non-whitespace character in each line

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            i = ftell(fp);
            //printf ("%ld ", i);
            ptr[++count] = i;
            fgets (data, 100, fp);
            //printf (" %s ", data);
            j = ftell(fp);
            diff = j-i;
            fseek(fp, -diff, SEEK_CUR);
        }
    }
    printf ("\n\n");

    for (i = 0; i <= count; i++) {
        fseek(fp, ptr[i], SEEK_SET);
        while ((ch = fgetc(fp)) == ' ')
            ptr[i]++;
    }

    
    int i1, i2, k;
    char str1[100], str2[100], temp[100], result[noOfLines][100];

    //copying source to the result file
    for (k = 0; k < noOfLines; k++) {
        fseek (fp, ptr[k], SEEK_SET);
        fgets (data, 100, fp);
        strcpy(result[k], data);
    }
    rewind(fp);
        
    // lexicographic sorting (NAIVE)
    for (i1 = 0; i1 < noOfLines; i1++) {
        for (i2 = i1+1; i2 < noOfLines; i2++) { // if lexicographically not sorted swap and replace in result file
            strcpy (str1, result[i1]);
            strcpy (str2, result[i2]);
            if (strcmp(str1, str2) > 0) {
                strcpy(temp, str1);
                strcpy(str1, str2);
                strcpy(str2, temp);

                strcpy(result[i1], str1);
                strcpy(result[i2], str2);
            }
                
            else {  // if ordering valid put as it is in result file
                strcpy(result[i1], str1);
                strcpy(result[i2], str2);
            }
                
        }
    }

    /*
    for (i = 0; i <= count; i++) {
        fseek (fp, ptr[i], SEEK_SET);
        fgets (data, 100, fp);
        printf ("%s", data);
    }
    */
    
    printf ("\n*******Result******\n");
    for (i = 0; i < noOfLines; i++)
        printf ("%s", result[i]);

    fclose(fp);
    return 0;
}
