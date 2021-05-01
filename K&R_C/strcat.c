#include <stdio.h>
#define SIZE 100

void str_cat(char *s, char *t);

int main(void){
    char s[SIZE] = "Hello";
    char t[SIZE] = "Nigga";
    str_cat(s, t);
    printf("%s", s);
}

void str_cat(char *s, char *t){
    int i = 0;
    int j = 0;
    while(s[i] != '\0'){
        i++;
    }
    while((s[i++] = t[j++]) != '\0'){
        ;
    }
    s[i] = '\0';
    return ;
}