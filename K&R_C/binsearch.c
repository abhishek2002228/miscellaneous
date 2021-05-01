#include <stdio.h>
#include <stdbool.h>

int binsearch(int x,const int v[], int n);

int main(void){
    int v[] = {0,1,2,3,4};
    int n = sizeof(v)/sizeof(int) ;
    int x = 5;
    int pos;
    pos = binsearch(x,v,n) ;
    printf("%d\n", pos);
}

int binsearch(int x,const int v[], int n){
    int high, low, mid;
    low = 0;
    high = n-1;
    mid = (low + high)/2;
    while(low<=high && v[mid]!= x){
        if(v[mid]<x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        mid = (low + high)/2;
    }
    if(v[mid] == x){
        return mid;
    }
    else{
        return -1;
    }
}