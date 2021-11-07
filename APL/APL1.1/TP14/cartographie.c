#include <stdio.h>
#include <stdlib.h>

int main (void){
    float f;
    double d;
    long double ld;
    char c;
    short int si;
    int i;
    long long unsigned int llui;

    printf("%p\n",&f);
    printf("%p\n",&d);
    printf("%p\n",&ld);
    printf("%p\n",&c);
    printf("%p\n",&si);
    printf("%p\n",&i);
    printf("%p\n",&llui);

    return EXIT_SUCCESS;
    

}