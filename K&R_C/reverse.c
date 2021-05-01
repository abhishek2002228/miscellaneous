#include <stdio.h>
#include <string.h>

void reverse(char s[], int start, int end);


int main(){
    char s[] = "olleH";
    reverse(s, 0, strlen(s) - 1);
    printf("%s\n", s);
    return 0;
}

void reverse(char s[], int start, int end){
    char c;
    if (start >= end){
        return;
    }
    reverse(s, start+1, end - 1);
    c = s[start];
    s[start] = s[end];
    s[end] = c;
    return;
}