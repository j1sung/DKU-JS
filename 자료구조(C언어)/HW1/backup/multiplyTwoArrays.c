#include <stdio.h>

/*
a * b = c

c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j]+ ... +a[i][n-1]*b[n-1][j] 
= sum(a[i][k]*b[k][j], k=0,...,n-1)
*/

multiplyTwoArrays( int **res, int **a, int **b, int m, int n, int q){
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