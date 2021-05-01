#define BUFSIZE 100
#define SIZE 4
#include <stdio.h>
#include <ctype.h>


int getint(int *);

int main()
{
        int n, array[SIZE];
        for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
                     ;

        int i;
        for(i= 0; i < SIZE; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
        return 0;
}

 int getch(void);
 void ungetch(int);

int getint(int *pn)
{
        int c, sign;
        while (isspace(c = getch())){
            ;
        }
        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c); 
                return 0;
        }

        sign = (c == '-') ? -1 : 1;

        if (c == '-' || c == '+')
                if(!isdigit(c = getch())){
                    ungetch((sign==1) ? '+' : '-');
                    return 0;
                }

        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');
        *pn *= sign;
        if (c != EOF)
                 ungetch(c);
        return c;
}

int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZE)
                printf("ungetch: can't push character\n");
        else
                buf[bufp++] = c;
}