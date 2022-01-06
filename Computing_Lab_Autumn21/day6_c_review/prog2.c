/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    Strength of password

Acknowledgements:

----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main (void) {
    char ch, pw[30];
    int i = 0;
    while ((ch = getch()) != '\n') {
        pw[i] = ch;
        ch = '?';
        printf ("%c", ch);
        i++;
    }
    pw[i] = '\0';

    int lower = 0, upper = 0, digit = 0, special = 0;
    int len = i;

    for (i = 0; i < len; i++) {
        if (islower(pw[i]))
            lower++;
        else if (isupper(pw[i]))
            upper++;
        else if (isdigit(pw[i]))
            digit++;
        else    
            special++;
    }

    //printf ("\n%s\n", pw);

    if (isPrime(lower) && isPrime(upper) && isPrime(digit) && isPrime(special))
        printf ("STRONG\n");
    else
        printf ("WEAK\n");
    

    return 0;
}