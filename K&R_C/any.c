#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int any(const char s1[],const char s2[]);

int main(void){
    int pos;
    char s1[] = "Abhishek";
    char s2[] = "zzzz";
    pos = any(s1, s2);
    printf("%d\n", pos);
    return 0;
}

int any(const char s1[], const char s2[]){
    int i, j;
    for(i = 0; s1[i] != '\0'; i++){
        for(j = 0; s2[j] != '\0'; j++){
            if(s1[i] == s2[j]){
                return i;
            }
        }
    }
    return -1;
}