#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

// 오름차순 삽입정렬
void insertion(int *a, int n){
    int i, j, move;
    int val;

    for(i=1; i<n; i++){
        val = a[i];
        j = i;
        if(a[j-1] > val)
            move = true;
        else 
            move = false;

        while(move){
            a[j] = a[j-1];
            j = j-1;
            if(j>0 && a[j-1]>val)
                move = true;
            else
                move = false;
        }
        a[j] = val;
    }
}

// 오름차순 버블정렬
void bubble(int *a, int n){
    int i, j;
    int val;

    for(i=n-1; i>0; i--){
        for(j=0; j<i; j++){
            if(a[j]>a[j+1]){
                val = a[j];
                a[j] = a[j+1];
                a[j+1] = val;
            }
        }
    }
}

// 오름차순 선택정렬
void selection(int *a, int n){
    int i, j, least;
    int val;

    for(i=0; i<n-1; i++){
        least = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[least])
                least = j;
        }
        val = a[least];
        a[least] = a[i];
        a[i] = val;
    }
}