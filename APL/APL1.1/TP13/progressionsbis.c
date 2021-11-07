#include<stdlib.h>
#include<stdio.h>

int main (void){

    int i,j,z,xvalue;
    int lignet1=2;
    int colonnet1=5;
    int lignet2=3;
    int colonnet2=5;
    int lignet3=5;
    int colonnet3=5;
    int t1[lignet1][colonnet1];
    int t2[lignet2][colonnet2];
    int t3[lignet3][colonnet3];
    
    
    for (i=0;i<lignet3;++i){
        /* t1 */
        if (i<lignet1){
            for (z=0,xvalue=1;z<colonnet1;++z,++xvalue){
                t1[i][z]=(xvalue);
                printf("%d\t",t1[i][z]);
            }
        }
        else {
            printf("\t\t\t\t\t");
        }
        printf("\t\t");
        
       
        /* t2 */
        if (i<lignet2){
            if(i==0){
            xvalue=1;
            }
            
            for (j=0;j<colonnet2;++j,++xvalue){
                if ((i>0)&&(j==0)){
                    xvalue=(t2[i-1][colonnet2-1]+1);
                }
                t2[i][j]=(xvalue);
                printf("%d\t",t2[i][j]);
            }
        }
        else
        {
            printf("\t\t\t\t\t");
        }
        
        printf("\t\t");

        /* t3 */
        for (z=0,xvalue=0;z<colonnet3;++z){
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
    printf("\n");


}