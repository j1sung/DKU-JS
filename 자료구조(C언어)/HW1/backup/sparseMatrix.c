#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_TERMS 10

typedef struct sparse{
    int col;
    int row;
    int value;
}MATRIX;

MATRIX *getSparse(int **a, int col, int row, int *cnt){
    int i,j;
    MATRIX *S;
    for(i=0; i<col; i++){
        for(j=0; j<row; j++){
            if(a[i][j])
                (*cnt)++;
        }
    }
    S = (MATRIX *)malloc(sizeof(MATRIX)*((*cnt)+1));

    //index=0 시작값 행, 열, 데이터 크기 넣기
    S[0].col = col;
    S[0].row = row;
    S[0].value = *cnt;

    //index=1 MATRIX 각 원소에 값 할당하기
    *cnt = 1;
    for(i=0; i<col; i++){
        for(j=0; j<row; j++){
            if(a[i][j]){
                S[*cnt].col = i;
                S[*cnt].row = j;
                S[(*cnt)++].value = a[i][j];
            }
        }
    }
    return S;
}
