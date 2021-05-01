#include <stdio.h>
#include <stdbool.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(void){
    unsigned int y = 15;
    unsigned int x = 16;
    int p = 3;
    int n = 4;
    x = setbits(x,p,n,y);
    printf("%u", x);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y){
    unsigned int op1 = (~(~0 << n) << (p+1-n));
    unsigned int op2 = (y << (p+1-n));
    unsigned int op3 = ~op1;
    return ((op3 & x) | (op1 & op2));
}