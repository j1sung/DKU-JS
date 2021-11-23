#include <stdio.h>

/* 
a + b = c

c[i][j] = a[i][j]+b[i][j]
*/

addTwoArrays(int **res, int **a, int **b, int m, int n){
    int r, c;

    for(r=0; r<m; r++){
        for(c=0; c<n; c++){
            res[r][c] = a[r][c] + b[r][c];
        }
    }
}