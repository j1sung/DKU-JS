#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void printSparse(int cnt, MATRIX *S){
    for(int i=0; i<cnt; i++){
        printf("%d\t%d\t%d\n", S[i].col, S[i].row, S[i].value);
    }
    printf("\n");
}

//Sparse Matrix
MATRIX *getSparse(int **a, int col, int row, int *cnt){
    int i,j;
    MATRIX *S;
    for(i=0; i<col; i++){
        for(j=0; j<row; j++){
            if(a[i][j])
                (*cnt)++; //0이 아닌 데이터 개수 구하기
        }
    }

    //초기값 때문에 공간이 1개 더 필요하다
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

//Transpose Matrix
MATRIX *transpose(MATRIX *a, int cnt){
    int n, i, j, currentb;
    MATRIX *b = (MATRIX*)malloc(sizeof(MATRIX)*cnt);

    //우선 첫 줄을 바꾸기
    n = a[0].value; 
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    //행을 기준으로
    if(n>0) {
        currentb = 1;
        for(i=0; i<a[0].col; i++){
            for(j=1; j<=n; j++){
                if(a[j].col==i){
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
    return b;
}