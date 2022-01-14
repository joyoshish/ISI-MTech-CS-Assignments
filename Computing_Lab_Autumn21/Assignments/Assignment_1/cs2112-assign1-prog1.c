/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Jan 14 2021
Program Description:    
                    Dominating folding

Acknowledgements:


----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char greater(char a, char b) {
  if (a >= b)
    return a;
  else
    return b;
}

void reverseString(char* str) {
    int l, i;
    char *begin_ptr, *end_ptr, ch;
    l = strlen(str);
    begin_ptr = str;
    end_ptr = str;
    for (i = 0; i < l-1; i++)
        end_ptr++;

    for (i = 0; i < l/2; i++) {
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;
        begin_ptr++;
        end_ptr--;
    }
}

int main (void) {
  int i, j, flag;
  char str[MAX], t[MAX], temp[MAX];
  scanf("%[^ ]%*c", str);
  scanf("%[^\n]%*c", t);

  for (i = 0; i < strlen(t); i++) {
    strcpy(temp, "");
    if (t[i] == 'L') {
      flag = 1;
      for (j = 0; j < (strlen(str)+1)/2; j++) {
        char max = greater(str[j], str[strlen(str)-j-1]);
        strncat(temp, &max, 1);
      }
    } else {
      for (j = 0; j < (strlen(str)+1)/2; j++) {
        char max = greater(str[j], str[strlen(str)-j-1]);
        strncat(temp, &max, 1);
      }
    }

    if (flag == 1)
      reverseString(temp);
    strcpy (str, temp);
    flag = 0;
    printf ("%s ", str);
  }

  return 0;
}
