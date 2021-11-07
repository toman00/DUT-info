#include<stdlib.h>
#include<stdio.h>

int main (void){

    int i,z,xvalue;
    int lignet1=2;
    int colonnet1=5;
    int lignet2=3;
    int colonnet2=5;
    int lignet3=5;
    int colonnet3=5;
    int t1[lignet1][colonnet1];
    int t2[lignet2][colonnet2];
    int t3[lignet3][colonnet3];
    
    
    /* t1 */
    for (i=0,xvalue=1;i<lignet1;++i){
        for (z=0,xvalue=1;z<colonnet1;++z,++xvalue){
            t1[i][z]=(xvalue);
            printf("%d\t",t1[i][z]);
        }
        printf("\n");
    }
    printf("\n");

    /* t2 */
    for (i=0,xvalue=1;i<lignet2;++i){
        
        printf("\n");
    }

    printf("\n");

    /* t3 */
    for (i=0,xvalue=0;i<lignet3;++i){
        for (z=0;z<colonnet3;++z){
            if (z<i){
                ++xvalue;  
            }
            else {
                xvalue=0;
            }
            t3[i][z]=(xvalue);
            printf("%d\t",t3[i][z]);
            
        }
        printf("\n");
    }


}