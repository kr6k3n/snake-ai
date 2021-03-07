#include <stdlib.h>
#include <stdio.h>

#ifndef UTILS
#define UTILS

extern void print_int_arr(int *arr, size_t arr_size);
void print_size_arr(size_t *arr, size_t arr_size);
extern void print_double_arr(double *arr, size_t arr_size);

extern double **two_D_double_array(size_t rows, size_t columns);

#endif