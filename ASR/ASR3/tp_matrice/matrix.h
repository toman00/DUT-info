#ifndef MATRIX_H
#define MATRIX_H


typedef struct {
int size;
int* c;
} matrix;

int get_coeff(matrix* m, int i, int j);

void set_coeff(matrix* m, int i, int j, int coeff);

matrix identity_matrix(int size);

matrix null_matrix(int size);

void print_matrix(matrix m);

matrix add_matrix(matrix m, matrix n);

matrix multiply_matrix(matrix m, matrix n);

#endif // MATRIX_h
