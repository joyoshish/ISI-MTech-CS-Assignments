/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    Sort strings acc. to their sum of ASCII value of characters

Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int val;
} strWval;

int getValue(char *s)
{
    int sum = 0;
    for (int i = 0; i < strlen(s); i++) {
        sum += s[i];
    }
    return sum;
}

void insertionSort(strWval arr[], int n)
{
    int i, key, j;
    char *s;
    for (i = 1; i < n; i++) {
        key = arr[i].val;
        s = arr[i].str;
        j = i - 1;
        while (j >= 0 && arr[j].val > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j+1].val = key;
        arr[j+1].str = s;
    }
}

int main (int argc, char **argv) {
    int i;
    strWval arr[argc];
    
    for (i = 0; i < argc-1; i++) {
        arr[i].str = argv[i+1];
        arr[i].val = getValue(argv[i+1]);
    }

    insertionSort(arr, argc-1);
    
    for (i = 0; i < argc-1; i++) {
        printf ("%s %d\n", arr[i].str, arr[i].val);
    }
    

    return 0;
}