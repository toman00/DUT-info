#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE* records;
	records=fopen("top10bis","r");
	int halloffame,i,letter;
	char pseudos[2];
	
	if (records){
		for (i=0;i<10;i++){
			fread(&halloffame,sizeof(int),1,records);
			printf("%d\t",halloffame);
			fread(pseudos,sizeof(char),3,records);
			for (letter=0;letter<3;letter++){
				printf("%c",pseudos[letter]);
			}
			printf("\n");
		}
	}
		
	fclose(records);

	return EXIT_SUCCESS;
}