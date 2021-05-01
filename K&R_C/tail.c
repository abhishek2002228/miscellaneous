#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#define default_tail 10
#define MAXLEN 1000
#define MAXLINES 5000

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int n);
int get_line(char s[], int maxlength);

int main(int argc, char *argv[]){
    int n = default_tail;
    int nlines;
    if (argc == 1)
    {
        ;
    }
    else if(argc == 2){
        argv++;
        n = atoi(++(argv[0]));
    }
    else{
        printf("Usage: tail -n\n");
    }


    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        printf("Printing Tail...\n");
        writelines(lineptr, nlines, n);
        return 0;
    }
    else{
        printf("error\n");
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0){
        if (nlines >= maxlines || (p = malloc(len*sizeof(char))) == NULL){
            return -1;
        }
        else{
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int n){
    int i;
    for (i = nlines - n; i < nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}

int get_line(char s[], int maxlength){
    int c, i;

    for (i = 0; i < maxlength - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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
