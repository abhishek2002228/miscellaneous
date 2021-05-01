#include <stdio.h>

void funct(int (*arr)[2]);

int main(void){
    int arr[2][2] = {{1, 2}, {3, 4}};
    funct(arr);
    printf("%d", **arr);
}

void funct(int (*arr)[2]){
    arr[0][0] = 100;
}