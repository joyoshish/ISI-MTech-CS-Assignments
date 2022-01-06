#include <stdio.h>
#include <stdlib.h>

#define MALLOC(type, size) (type *)malloc(size*sizeof(type))

void free_dynamic(void *ptr){
    free(ptr);
}

char *single_char_array(int size){
    return MALLOC(char, size);
}

char **double_char_array(int row, int col){
    char **c;
    c = MALLOC(char*, row);
    int i =0;
    for(i = 0; i < row; i++)
        c[i] = MALLOC(char, col);
    return c;
}