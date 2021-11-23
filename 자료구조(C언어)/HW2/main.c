#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "sort.h"

int main(void){
    int *a, n;
    int i, j, c;
    int flag = 0;
    long start, end, result = 0;
    srand(time(NULL)); // rand()함수값이 실행될 때마다 다 다른 랜덤한 값을 불러오기 위해 srand()를 선언하고 계속 바뀌는 time을 seed값으로 주어서 계속 다른 값들을 채워넣는다.
    
    printf("정렬할 데이터의 크기(10000 ~ 1000000): ");
    scanf("%d", &n);
    printf("\n");

    a = (int*)malloc(sizeof(int)*n);
    
    printf("모든 출력은 20개로 제한하였다.\n\n");

    for(c=0; c<15; c++){
        for(i=0; i<n; i++){
            a[i] = (rand()%n)+1; // 1~n까지의 수를 배열에 넣는다.
            for(j=0; j<i; j++){
                if(a[i] == a[j])
                    i--;
            }
        }

        printf("<정렬 전>\n");
        print_array(a, n);
        
        if(0<=flag && flag<5){
            printf("<삽입 정렬 -> ");
            start = get_runtime();
            insertion(a, n);
            end = get_runtime();

        }
        else if(5<=flag && flag<10){
            printf("<버블 정렬 -> ");
            start = get_runtime();
            bubble(a, n);
            end = get_runtime();
        }
        
        else{
            printf("<선택 정렬 -> ");
            start = get_runtime();
            selection(a, n);
            end = get_runtime();
        }

        printf("정렬 후>\n");
        result += (end-start);
        print_array(a, n);
        printf("걸린시간>> %ld\n\n", end-start);

        if(flag == 4 || flag == 9 || flag == 14){
            printf("평균값>> %ld\n\n\n", result/5);
            result = 0;
        }
        flag++;
    }
    free(a);

    return 0;
}