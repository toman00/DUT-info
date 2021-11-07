/*a=1 ; b=2 ; c=3
*p=2
*q=
 */

#include <stdio.h>
#include <stdlib.h>

int main (void){
    int a = 1, b = 2, c = 3;
    int *p, *q;
    

    p=&a;
    q=&c;
    *p=(*q)++;
    p=q;
    q=&b;
    *p-=*q;
    ++*q;
    *p*=*q;
    a=++*q**p;
    p=&a;
    *q=*p/(*q);
    printf("*p=%p\n",*p);
    printf("*q=%p\n",*q);
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    printf("c=%d\n",c);
    printf("p=%p\n",p);
    printf("q=%p\n",q);

}