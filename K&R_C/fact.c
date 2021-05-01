#include <stdio.h>
#include <stdbool.h>

int fact(int n);

int main(){
    int num;
    int c;
    int answer;
    do
    {
        printf("Enter a Number: ");
        scanf("%d", &num);
    }
    while(num < 0);

    if(num == 0){
        answer = 1;
        printf("Answer %d\n", answer);
        return 0;
    }

    answer = fact(num);
    printf("Answer %d\n", answer);
    return 0;
}

int fact(int n){
    int i;
    int answer = 1      ;
    for(i=1; i<=n; ++i){
        answer = answer * i;
    }
    return answer;
}