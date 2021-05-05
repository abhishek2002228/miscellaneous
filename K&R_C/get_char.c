#include <unistd.h>
#include <stdio.h>

int get_char(void){
    char c;
    return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}

int main(void){
    int c;

    while((c=getchar()) != EOF){
        printf("%c", c);
        c = getchar();
    }

    return 0;
}