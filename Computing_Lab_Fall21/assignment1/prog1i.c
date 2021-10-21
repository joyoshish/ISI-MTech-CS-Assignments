/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Oct 7 2021
Program Description:    Suppose you are playing a game in turn with the computer.
                        Total n number of sticks are to be picked up in this game.
                        Whoever picks the last one loses the game. Neither the
                        computer nor you can pick up more than 3 sticks at a time.
                        Nobody can skip a turn, i.e. at least one stick is to be picked
                        up in a turn. Write a program to let the following happen.
                        
                        i)    The computer wins if it has the first turn.

        Winning strategy for the 1st player(the Computer):

                        i) Choose initial number of sticks(N) to be not in the form 4k+1
                        (where k = 0,1,2,3,...).
                        ii) Make the first move and leave the opponent with 4k+1 sticks
                        (where N>4k+1) by picking 1, 2 or 3 sticks.
                        iii) In subsequent moves, pick sticks such that the sum of `the 
                        sticks picked by opponent in the previous move` and `sticks picked 
                        by you in current move` equals 4.

                        [Now whatever move the opponent makes, the opponent will be left 
                        with 1 stick in the end, as we are ensuring the sum of the moves
                        by 2 players remain 4; thereby reducing the number of sticks(N)
                        by 4 and leaving the opponent with a single stick in the end.]
            


Acknowledgements:

----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxNoOfSticks 30

int checkForm(int n)        //check if n is in the form 4k+1
{
    int i;
    for (i = 0; i <= MaxNoOfSticks/4; i++) {
        if (4*i + 1 == n)
            return 1;
    }
    return 0;
}

int findForm(int n)         //find number < n, which is in the form of 4k+1
{
    int i, p=0;
    for (i = 0; i <= MaxNoOfSticks/4; i++) {
        if (n > 4*i)
            p = i;
        else if (n == 4*i)
            p = i-1;
    }
    return 4*p+1;
}

int initNoOfSticks()        //produce initial number of sticks(not in the form 4k+1) 
{
    srand(time(0));
    int ret = 1;
    while(checkForm(ret)) {
        ret = rand()%MaxNoOfSticks + 1;     //avoid initial no. of sticks to be 0 by adding 1
    }
    return ret;
}

int main(void)
{
    printf ("~~~~~~~~The Takeaway Game~~~~~~~~\n");
    int n = initNoOfSticks();
    printf ("\nInitial number of sticks = %d\n", n);
    printf ("\nComputer moves first, player moves second.\n");
    int spcl = findForm(n);

    int round = 1, computerMove, playerMove;
    
    while (1) {
        if (round == 1) {
            computerMove = n - findForm(n);
            printf ("\nComputer picks %d stick(s)\n", computerMove);
            n -= computerMove;
            printf ("Remaining sticks: %d\n", n);
            printf ("Pick sticks(1, 2, 3): ");
            scanf ("%d", &playerMove);
            n -= playerMove;
            printf ("Remaining sticks: %d\n", n);
            if (n == 0) {
                printf ("\nComputer wins!\n");
                break;
            }
        }
        else {
            computerMove = 4 - playerMove;
            printf ("\nComputer picks %d stick(s)\n", computerMove);
            n -= computerMove;
            printf ("Remaining sticks: %d\n", n);
            printf ("Pick sticks(1, 2, 3): ");
            scanf ("%d", &playerMove);
            n -= playerMove;
            printf ("Remaining sticks: %d\n", n);
            if (n == 0) {
                printf ("\nComputer wins!\n");
                break;
            }
        }
    }



    return 0;
}