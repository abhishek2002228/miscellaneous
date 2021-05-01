#include <stdio.h>

void escape(char s[], const char t[]);

int main(void){
    char s[1000];
    char t[] = "Abhishek\tRevinipati\tlol";
    escape(s,t);
}

void escape(char s[], const char t[]){
    char c;
    int i = 0;
    int j = 0;
    while((c=t[i]) != '\0'){
        if(c=='\t'){
            s[j++] = '\\';
            s[j++] = 't';
        }
        else{
            s[j++] = c;
        }
        ++i;
    }
    s[j] = '\0';
}