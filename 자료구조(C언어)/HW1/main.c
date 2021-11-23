#include <stdio.h>
#include "common.h"
#include "arithmetic.h"
#include "matrix.h"
#include <time.h>

// main함수 작성
int main(void){
    int i,j;
    int m, n, q;
    int r, c;
    int **a, **b, **res1, **res2, **res3, **x, **y, **res4;

    int cnt1=0, cnt2=0, cnt3=0, cnt4=0;
    long start, end;

    //같은 크기의 행렬 행과 열 입력
    printf("i j: ");
    scanf("%d %d", &i, &j);

    //다른 크기의 행렬 행과 열 입력
    printf("m n q: ");
    scanf("%d %d %d", &m, &n, &q);

    //같은 크기의 행렬 - 덧셈, 뺄셈, 나눗셈
    a = array(i,j);
    b = array(i,j);
    res1 = array(i,j);
    res2 = array(i,j);
    res3 = array(i,j);

    for(r=0; r<i; r++){
        for(c=0; c<j; c++){
            a[r][c] = mrand(i);
            b[r][c] = mrand(j);
        }
    }

    //다른 크기의 행렬 - 곱셈

    x = array(m,n);
    y = array(n,q);
    res4 = array(m,q);

    for(r=0; r<m; r++){
        for(c=0; c<n; c++)
            x[r][c] = mrand(m);
    }

    for(r=0; r<n; r++){
        for(c=0; c<q; c++)
            y[r][c] = mrand(n);
    }
    
    printf("array: a\n");
    printArray(a, i, j);
    printf("array: b\n");
    printArray(b, i, j);
    printf("array: x\n");
    printArray(x, m, n);
    printf("array: y\n");
    printArray(y, n, q);

    //연산 수행
    //덧셈, 뺄셈, 나눗셈
    start = get_runtime();
    addTwoArrays(res1, a, b, i, j);
    subtractTwoArrays(res2, a, b, i, j);
    ElementWiseDivideTwoArrays(res3, a, b, i, j);
    end = get_runtime();

    printf("<<덧셈, 뺄셈, 나눗셈>>\nstart: %ld\nend: %ldf\n 걸린시간: %ld\n\n", start, end, end-start);

    printf("array: +\n");
    printArray(res1, i, j);
    printf("array: -\n");
    printArray(res2, i, j);
    printf("array: /\n");
    printArray(res3, i, j);

    //곱셈
    start = get_runtime();
    multiplyTwoArrays(res4, x, y, m, n, q);
    end = get_runtime();

    printf("<<곱셈>>\nstart: %ld\nend: %ld\n 걸린시간: %ld\n\n", start, end, end-start);

    printf("array: *\n");
    printArray(res4, m, q);

    //같은 크기의 행렬 2개 희소 행렬 변환
    start = get_runtime();
    MATRIX *A = getSparse(a, sizeof(a) / (sizeof(int) * j), i, &cnt1);
    MATRIX *B = getSparse(b, sizeof(b) / (sizeof(int) * j), i, &cnt2);
    end = get_runtime();

    printf("<<같은 크기 행렬들-> 희소 행렬>>\nstart: %ld\nend: %ld\n 걸린시간: %ld\n\n", start, end, end-start);

    printf("array: a -> sparse: A\n");
    printSparse(cnt1, A);
    printf("array: b -> sparse: B\n");
    printSparse(cnt2, B);

    //다른 크기의 행렬 2개 희소 행렬 변환
    start = get_runtime();
    MATRIX *X = getSparse(x, sizeof(x) / (sizeof(int) * n), i, &cnt3);
    MATRIX *Y = getSparse(y, sizeof(y) / (sizeof(int) * n), i, &cnt4);
    end = get_runtime();

    printf("<<다른 크기 행렬들 -> 희소 행렬>>\nstart: %ld\nend: %ld\n 걸린시간: %ld\n\n", start, end, end-start);

    printf("array: x -> sparse: X\n");
    printSparse(cnt3, X);
    printf("array: y -> sparse: Y\n");
    printSparse(cnt4, Y);

    //같은 크기의 행렬-> 전치 행렬 변환
    start = get_runtime();
    MATRIX *At = transpose(A, cnt1);
    MATRIX *Bt = transpose(B, cnt2);
    end = get_runtime();

    printf("<<같은 크기 행렬들 -> 전치 행렬>>\nstart: %ld\nend: %ld\n 걸린시간: %ld\n\n", start, end, end-start);

    printf("sparse: A -> sparse: At\n");
    printSparse(cnt1, At);
    printf("sparse: B -> sparse: Bt\n");
    printSparse(cnt2, Bt);

    //다른 크기의 행렬-> 전치 행렬 변환
    start = get_runtime();
    MATRIX *Xt = transpose(X, cnt3);
    MATRIX *Yt = transpose(Y, cnt4);
    end = get_runtime();

    printf("<<다른 크기 행렬들 -> 전치 행렬>>\nstart: %ld\nend: %ld\n 걸린시간: %ld\n\n", start, end, end-start);

    printf("sparse: X -> sparse: Xt\n");
    printSparse(cnt3, Xt);
    printf("sparse: Y -> sparse: Yt\n");
    printSparse(cnt4, Yt);

    freeArray(a, i);
    freeArray(b, i);
    freeArray(res1, i);
    freeArray(res2, i);
    freeArray(res3, i);
    freeArray(x, m);
    freeArray(y, n);
    freeArray(res4, m);

    return 0;
}   