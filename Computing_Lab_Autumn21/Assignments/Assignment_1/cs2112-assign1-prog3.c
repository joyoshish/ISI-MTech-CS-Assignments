/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Jan 14 2021
Program Description:    
                    Expanding characters

Acknowledgements:


----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, char **argv) {
  int i, j;
  
  for (i = 0; i < strlen(argv[1]); i++) {
    if (!isdigit(argv[1][i])) 
      printf ("%c", argv[1][i]);
    else {
      if (!isdigit(argv[1][i+1])) {
        for (j = 0; j < argv[1][i] - '0'; j++) {
          printf ("%c", argv[1][i+1]);
        }
      }
      else  
        printf ("%c", argv[1][i]);
    }
    if (i == strlen(argv[1]) - 1 && isdigit(argv[1][i]))
      printf ("%c", argv[1][i]);
  }

  return 0;
}
