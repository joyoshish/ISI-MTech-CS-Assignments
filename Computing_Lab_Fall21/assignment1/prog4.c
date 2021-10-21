/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:  
                    Let us define a string, comprising English alphabets, as NICE
                    if each vowel within it are equidistant from its successor and
                    predecessor vowel, if applicable. E.g., “rhythm”, “cool”,
                    “malayalam” are NICE strings. Write a program to verify
                    whether a given string is NICE or not. You are required to
                    take the string as a direct input without asking for its length.


Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isVowel (char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    else
        return 0;
}

int main(void)
{
    int count = 0, nice = 0, i, j, firstPos, secondPos, prev, current, difference;
    char str[100];
    printf ("Enter string: ");
    scanf("%[^\n]s",str);
    
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (isVowel(str[i])) {
            count++;
            if (count == 1) {   // if the first vowel
                firstPos = i;
            }
            else if (count == 2) {  // if the second vowel
                secondPos = i;
                prev = secondPos;
                difference = secondPos - firstPos;
            }
            else {
                current = i;
                if (current - prev == difference)
                    nice = 1;
                else 
                    nice = 0;
                prev = current;
            }
        }
    }

    if (count == 1 || count == 2 || count == 0)
        nice = 1;
    
    if (nice == 1)
        printf ("\nNICE\n");
    else
        printf ("\nNOT NICE\n");


    return 0;
}