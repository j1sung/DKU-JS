#include <stdio.h>
#include <time.h>
#include "common.h"

// 출력은 10~20개 정도로 보여줌
void print_array(int *a, int n){
    for(int i=0; i<20; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

long get_runtime(void)
{
   clock_t start;
   start = clock();
   return ((long)((double)start * 100.0 / (double)CLOCKS_PER_SEC));
}