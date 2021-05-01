#include <stdio.h>
#include <ctype.h>

int main(void){
    int c;
    c = getchar();
    if(isdigit(c)){
        printf("Digit\n");
    }
    else{
        printf("Not Digit\n");
    }

    return 0;
}