#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void squeeze(char s1[], const char s2[]); // removes characters from s1 that are common with s2 

int main(void){
    char s1[] = "Abhishek";
    char s2[] = "ha";
    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], const char s2[]){
    int i, j, k;
    for(i=k=0; s1[i] != '\0'; i++){
        int flag = 0;
        for(j = 0; s2[j] != '\0'; j++){
            if(tolower(s1[i])==tolower(s2[j])){
                flag++;
            }
        }
        if(flag == 0){
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}