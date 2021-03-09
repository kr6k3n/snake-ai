#include <stdlib.h>
#include <stdio.h>

#ifndef UTILS
#define UTILS
//universal data types
typedef double *tensor;


extern void print_int_arr(int *arr, size_t arr_size);
void print_size_arr(size_t *arr, size_t arr_size);
extern void print_double_arr(double *arr, size_t arr_size);

extern double **two_D_double_array(size_t rows, size_t columns);
extern int **two_D_int_array(size_t rows, size_t columns);

extern double rand1();
#endif