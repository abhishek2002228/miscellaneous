#include <stdio.h>
#include <stddef.h>
int main(void){
    char *p = NULL;
    size_t x = sizeof(*p);

    printf("%zu\n", x);
}