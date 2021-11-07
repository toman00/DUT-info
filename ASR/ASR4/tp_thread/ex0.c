#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* affiche tous les éléments d'un tableau (1er arg), de taille n, la fonction
 * utilisé pour print est entré par référence en dernier argument */
void map(void *base,size_t n ,size_t size_elem,void(*f)(void *)){
	int i;
	char *ptr = (char*)base; 
	for(i=0;i<n;i++) 
		f((void*)(ptr+i*size_elem)); 
}

void print_int(void* integer) {
	printf("%d ", *(int*)integer);
}

void print_string(void* string) {
	printf("%s ", *(char**)string);
}

int cmp_int(const void* int1, const void* int2) {
	int ret = -1; 
	if (*(int*)int1 == *(int*)int2) {
		ret = 0;
	}
	else if (*(int*)int1 > *(int*)int2) {
		ret = 1;
	}
	return ret;
}

int cmp_string(const void* string1, const void* string2) {
	return strcmp(*(char**)string1,*(char**)string2);
}

int main(){
	int    t1[10]={12,-7,1,-16,3,19,7,1,5,0};
	char * t2[]={"chou","joujou","bijou","genou",
		"caillou","hibou","pou"};

		map(t1,10,sizeof(int),print_int);
		printf("\n");
		map(t2,7,sizeof(char*),print_string);
		printf("\n");
		
		qsort(t1,10,sizeof(int),cmp_int);
		map(t1,10,sizeof(int),print_int);
		printf("\n");
		qsort(t2,7,sizeof(char *),cmp_string);
		map(t2,7,sizeof(char*),print_string);
		printf("\n");
}
