#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef UTILS
#define UTILS
//universal data types
typedef double *tensor;


extern void print_int_arr(int *arr, size_t arr_size);
void print_size_arr(size_t *arr, size_t arr_size);
extern void print_double_arr(double *arr, size_t arr_size);
extern void copy_tensor(tensor to, tensor from, size_t size);

extern double **two_D_double_array(size_t rows, size_t columns);
extern int **two_D_int_array(size_t rows, size_t columns);

extern int get_max_index(double *arr, size_t arr_size);
extern double rand1();

extern bool is_number(char *string);
#endif