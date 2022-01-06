/*----------------------------------------------------

Name: Joyoshish Saha
Roll number: CS2112
Date: Nov 9 2021
Program Description:    
                    Number of preprocessor lines in source code

Acknowledgements:

----------------------------------------------------*/

#include <stdio.h>

#define IMPLY(x, y) ((!x) || y)
#define SWAP(x,y) do {\
    unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1];\
    memcpy(swap_temp,&y,sizeof(x));\
    memcpy(&y,&x,       sizeof(x));\
    memcpy(&x,swap_temp,sizeof(x));\
} while(0)
#define MIN(x, y) ((x)<(y))?(x):(y)
#define MAX(x, y) ((x)>(y))?(x):(y)
#define INF_PRINT(x) while(1) printf("%d\n", x);

int main() {
	char ch;
	FILE *fp = fopen(__FILE__,"r");
   	if (fp == NULL) return 0;
   	int count = 0;
   	char str[20];

   	while ((ch = fgetc(fp) )!= EOF) {
		if(ch == '#') {
			while((ch = fgetc(fp) ) != EOF && ((ch != '{') && (ch != '\n'))) ;
			if(ch == '\n') count++;
			else if(ch == '{') {
				while((ch = fgetc(fp) ) != EOF && (ch != '}')) {
						if(ch == '\n') 
						    count++;
				}
				if(ch == '}') 
                    count++;
			}
		}
    }

    printf("Number of preprocessor lines: %d\n", count-1);
   	fclose(fp);

	return 0;
}