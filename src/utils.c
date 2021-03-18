#include "utils.h"

void print_int_arr(int *arr, size_t arr_size)
{
	printf("[");
	for (size_t i = 0; i < arr_size; i++)
		if (i != arr_size - (size_t)1)
			printf("%d, ", arr[i]);
		else
			printf("%d]\n", arr[i]);
}

void print_size_arr(size_t *arr, size_t arr_size)
{
	printf("[");
	for (size_t i = 0; i < arr_size; i++)
		if (i != arr_size - (size_t)1)
			printf("%zu, ", arr[i]);
		else
			printf("%zu]\n", arr[i]);
}

void print_double_arr(double *arr, size_t arr_size)
{
	printf("[");
	for (size_t i = 0; i < arr_size; i++)
		if (i != arr_size - (size_t)1)
			printf("%f, ", arr[i]);
		else
			printf("%f]", arr[i]);
}

double **two_D_double_array(size_t rows, size_t columns)
{
	double** arr = (double **)malloc(rows * sizeof(double *));
	for (int i = 0; i < rows; i++)
		arr[i] = (double *)malloc(columns * sizeof(double));
	return arr;
}

int **two_D_int_array(size_t rows, size_t columns)
{
	int **arr = (int **)malloc(rows * sizeof(int *));
	for (size_t i = 0; i < rows; i++)
		arr[i] = (int *)malloc(columns * sizeof(int));
	return arr;
}


double rand1()
{
	return (double)rand() / (double)RAND_MAX;
}

int get_max_index(double *arr, size_t arr_size)
{
	double max = -1;
	int index = -1;
	for (size_t i = 0; i < arr_size; i++)
		if (arr[i] > max){
			max = arr[i];
			index = i;
		}
	return index;
}

bool is_number(char *string)
{
	size_t length = strlen(string);
	for (size_t i = 0; i < length; i++)
		if (!isdigit(string[i]))
			return false;
	return true;
}