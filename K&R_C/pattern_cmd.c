#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char s[], int lim);

int main(int argc, char *argv[]){
    char line[MAXLINE];
    int found = 0;
    char *p = NULL;
    int len;

    if (argc != 2)
    {
        printf("Please enter 1 pattern");
    }
    else{
        while((len = get_line(line, MAXLINE)) > 0){
            if(line[len-1] == '\n'){
                line[len - 1] = '\0';
            }
            if((p =strstr(line, argv[1])) != NULL){
                printf("%s in %td\n", line, p - line);
                found++;
            }
        }
    }

    return found;
}

int get_line(char s[], int lim){
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}