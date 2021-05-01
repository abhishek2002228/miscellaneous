#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int strindex(const char s[], const char t[]);
void reverse(char s[]);

/*int main(void){
    char line[MAXLINE];
    int found = 0;
    char pattern[MAXLINE];
    get_line(pattern, MAXLINE);
    int len;
    char rev_pattern[MAXLINE];
    char rev_line[MAXLINE];
    strcpy(rev_pattern, pattern);
    
    reverse(rev_pattern);

    while((len = get_line(line, MAXLINE)) > 0){
        if(strindex(line, pattern) >= 0){
            if(line[len-1] != '\n'){
                printf("\n");
            }
            printf("%s", line);
            found++;
            if(line[len-1] != '\n'){
                printf("\n");
            }
        }
    }
    printf("%d\n", found);
}*/

int main(vod)
{
    char s1[] = "BHabhilalabhia";
    char s2[] = "bhi";
    int x;
    reverse(s1);
    reverse(s2);
    x = strindex(s1, s2);
    printf("%d", x);
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

int strindex(const char s[], const char t[])
{
    int i, j, k;
    int pos = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (k = i, j = 0; t[j] != '\0' && s[k] != '\0'; j++)
        {
            if (s[k] == t[j])
            {
                k++;
                pos = i;
            }
            else
            {
                break;
            }
        }
        if (t[j] == '\n' || t[j] == '\0')
        {
            return pos;
        }
    }

    return -1;
}
