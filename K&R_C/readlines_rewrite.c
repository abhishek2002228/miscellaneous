#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define MAXLINES 500
#define ALLOCSIZE MAXLEN *MAXLINES
int get_line(char s[], int lim);
int readlines(char *lineptr[], char array[], int maxlines);

int main(void)
{
    char array[ALLOCSIZE];
    char *lineptr[MAXLINES];
    readlines(lineptr, array, MAXLINES);
    printf("%s\n", lineptr[1]);
}

int get_line(char s[], int lim)
{
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

int readlines(char *lineptr[], char array[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    p = array + strlen(array);
    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if((nlines >= maxlines) || (strlen(array) + len > ALLOCSIZE)){
            return -1;
        }
        else{
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p = p + len;
        }
    }
    return nlines;
}