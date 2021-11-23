#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"

int **array(int rows, int cols){
    int **arr;
    int i;

    arr = (int **) malloc(sizeof(int)*rows);
    for(i=0; i<rows; i++)
        arr[i] = (int *) malloc(sizeof(int)*cols);

    return arr;
}

void freeArray(int **arr, int rows){
    int r;
    for(r=0; r<rows; r++)
        freeVector(arr[r]);
    free(arr);
}

void freeVector( int *vec ){
    free( vec );
}

void printArray(int **arr, int rows, int cols){
    int r,c;

    for(r=0; r<rows; r++){
        for(c=0; c<cols; c++)
            printf("\t %d", arr[r][c]);
        printf("\n");
    }
    printf("\n");
}

int mrand(int range){
    return rand() % range;
}

long get_runtime(void)
{
   clock_t start;
   start = clock();
   return ((long)((double)start * 100.0 / (double)CLOCKS_PER_SEC));
}