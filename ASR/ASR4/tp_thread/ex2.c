#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

typedef struct somme_th {
    int start;
    int n;
    int m;
    int sum;
} somme_th;

void *thread(void* strct) {
    somme_th s = *(*somme_th) strct;
    int i;
    for (i=s.start; i<s.n; i+=s.m) {

    }

    return null;
}

int main(int argc, char** argv){
    int i, nb_threads = atoi(argv[2]), goal = atoi(argv[2]);
    somme_th s = calloc (nb_threads, sizeof(somme_th));


    for (i=0; i < nb_threads; i++) {
        s[i].start = i + 1;
        s[i].m = nb_threads;
        s[i].n = goal;
        assert(pthread_create(&threads[i], NULL, thread, s+i) == 0);
    }

}