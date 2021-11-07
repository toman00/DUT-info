#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
// Cherche le coefficient à l'indice i,j dans une matrice carrée.
int get_coeff(matrix* m, int i, int j) {
    return m->c[i * m->size + j];
}

// Place un coefficient à l'indice i,j dans une matrice carrée.
void set_coeff(matrix* m, int i, int j, int coeff) {
    m->c[i * m->size + j] = coeff;
}

// Create a matrix and fill with 1 the diagonal.
matrix identity_matrix(int size) {
    matrix m;
    m.size = size;
    m.c = (int*) calloc(size*size, sizeof(int));
    for(int i = 0; i < size; i++) {
	    set_coeff(&m, i, i, 1);
    }
    return m;
}

// Create a matrix with 0 at each position
matrix null_matrix(int size) {
    matrix m;
    m.size = size;
    m.c = (int*) calloc(size*size, sizeof(int));

    for(int i = 0; i < size; i++) {
        set_coeff(&m, i, i, 0);
    }
    return m;
}

/* Print a matrix */
void print_matrix(matrix m) {
    for(int i = 0; i < m.size*m.size; i++) {
        if (i % m.size == 0 && i > 0) {
    	    printf("\n");
        }
        printf("%d", m.c[i]);
    }
    printf("\n");
}

/* Add up 2 matrixes */
matrix add_matrix(matrix m, matrix n) {
    matrix sum;
    int add;
    // abort the sum if different size
    if (m.size != n.size) {
        return m;
    }
    sum.size = m.size;
    sum.c = (int*) calloc(m.size*m.size, sizeof(int));

    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            add = get_coeff(&m, i, j) + get_coeff(&n, i, j); 
            set_coeff(&sum, i, j, add);
        }
    }
    return sum;
}


/* Multiplies 2 matrixes */
matrix multiply_matrix(matrix m, matrix n) { 
    matrix final;
    int multiplication;
    // abort the sum if different size
    if (m.size != n.size) {
        return m;
    }
    final.size = m.size;
    final.c = (int*) calloc(m.size*m.size, sizeof(int));

    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            multiplication = get_coeff(&m, i, j) * get_coeff(&n, i, j); 
            set_coeff(&final, i, j, multiplication);
        }
    }
    return final;
}