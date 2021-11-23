#ifndef _MATRIX_

#define _MATRIX_

typedef struct sparse{
    int col;
    int row;
    int value; //0이 아닌 데이터의 수
}MATRIX;

void printSparse(int, MATRIX *);
MATRIX *getSparse(int **, int, int, int *);
MATRIX *transpose(MATRIX *, int);

#endif
