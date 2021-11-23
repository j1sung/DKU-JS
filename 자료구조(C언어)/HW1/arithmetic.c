#include <stdio.h>
#include "arithmetic.h"

/* 
a + b = c

c[i][j] = a[i][j]+b[i][j]
*/

void addTwoArrays(int **res, int **a, int **b, int m, int n){
    int r, c;

    for(r=0; r<m; r++){
        for(c=0; c<n; c++){
            res[r][c] = a[r][c] + b[r][c];
        }
    }
}

/*
a - b = c

c[m][n] = a[m][n] - b[m][n]
*/

void subtractTwoArrays(int **res, int **a, int **b, int m, int n){
    int r, c;

    for(r=0; r<m; r++){
        for(c=0; c<n; c++){
            res[r][c] = a[r][c] - b[r][c];
        }
    }
}

/*
a / b = c

c[m][n] = a[m][n] / b[m][n]
*/

void ElementWiseDivideTwoArrays(int **res, int **a, int **b, int m, int n){
    int r, c;

    for(r=0; r<m; r++){
        for(c=0; c<n; c++){
            // 값이 둘 중에 하나라도 0이 있다면 결과값 0 대입
            if(a[r][c] == 0 || b[r][c] == 0)
                res[r][c] = 0;
            // 값이 둘 다 0이 아니라면 나눈 값을 대입
            else
                res[r][c] = a[r][c] / b[r][c];
        }
    }
}

/*
a * b = c

c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j]+ ... +a[i][n-1]*b[n-1][j] 
= sum(a[i][k]*b[k][j], k=0,...,n-1)
*/

void multiplyTwoArrays( int **res, int **a, int **b, int m, int n, int q){
    int r, c, k;
    int sum;

    for(r=0; r<m; r++){
        for(c=0; c<q; c++){
            sum = 0;
            for(k=0; k<n; k++)
                sum += a[r][k] + b[k][c];
            res[r][c] = sum;
        }
    }
}