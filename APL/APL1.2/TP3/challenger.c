#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    FILE* records;
    int score,i,letter, halloffame[9],newscore;
    char pseudos[2];
    records=fopen("top10","r+");
    if (argc<3){
        printf("2 arguments needed !");
        exit(1);
    }
    
    newscore=strtol(argv[1],NULL,10);
    printf("%d\n",newscore);
    if (records){
      for (i=0;i<10;i++){
            fread(&score,sizeof(int),1,records);
            halloffame[i]=score;
            if (newscore > halloffame[i]){
                fseek(records,-(sizeof(int)),SEEK_CUR);
                fwrite(&newscore,sizeof(int),1,records);
                fwrite(argv[2],1,3,records);
            }
        }
        
    }

    
    else printf("Cant' open the file");
    
    fclose(records);

    return EXIT_SUCCESS;
}