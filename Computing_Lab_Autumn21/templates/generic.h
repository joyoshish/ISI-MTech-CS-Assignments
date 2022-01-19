#include <stdio.h>
#define Malloc(n,type) (type *)malloc((unsigned) ((n)*sizeof(type)))
#define Realloc(loc,n,type) (type *)realloc( (char *)(loc), (unsigned) ((n)*sizeof(type)))


#define MALL_1D_ARR(type, a, cols) a = (type *)malloc(cols*sizeof(type));

#define MALL_2D_ARR(type, a, rows, cols) {\
	\
	a = (type **)malloc(rows*sizeof(type *));\
	for(i=0;i<rows;i++)\
		a[i] = (type *)malloc(cols*sizeof(type));\
}



void swap_file(char *f1, char *f2)
{
	FILE *fp1, *fp2;
	char ch1, ch2;

	fp1 = fopen(f1, "r+");
	fp2 = fopen(f2, "r+");
	while( (ch1 = fgetc(fp1)) != EOF && (ch2 = fgetc(fp2)) != EOF)
	{
		fseek(fp1,-1,SEEK_CUR);
		fseek(fp2,-1,SEEK_CUR);
		fputc(ch2,fp1);
		fputc(ch1,fp2);
	}
	if(ch1 == EOF && ch2 != EOF)
	{
		fputc(EOF,fp2);
		printf("First Over\n");
		while( (ch2 = fgetc(fp2))!= EOF)
			fputc(ch2,fp1);
	}
	else if(ch2 == EOF && ch1 != EOF)
	{
		fputc(EOF,fp1);
		printf("Second Over\n");
		do
		{
			fputc(ch1,fp2);
		}while( (ch1 = fgetc(fp1))!= EOF);
	}


	fclose(fp1);
	fclose(fp2);
}
