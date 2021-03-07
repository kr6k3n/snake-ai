#include "connection_layer.h"
double sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

double init_weight()
{
	return (double)rand() / (double)RAND_MAX;
}
tensor rand_tensor(size_t tensor_size)
{
	tensor result = (tensor) malloc(sizeof(tensor)*tensor_size);
	for (size_t i = 0; i < tensor_size; i++)
		result[i] = init_weight();    
	return result;
}

connection_layer *new_connection_layer(size_t left_side, size_t right_side){
	connection_layer *cl = (connection_layer *)malloc(sizeof(connection_layer));
	cl->left_side = left_side;
	cl->right_side = right_side;
	//init weights
	weight** weights =(weight**) two_D_double_array(right_side, left_side);
	for (size_t i = 0; i < right_side; i++)
		for (size_t j = 0; j < left_side; j++){
			weights[i][j] = init_weight();
		}
	cl->weights = weights;
	//init biases
	double* biases = (double *)malloc(sizeof(double) * right_side);
	for (size_t i = 0; i < right_side; i++)
		biases[i] = init_weight();
	cl->biases = biases;

	return cl;
}

tensor* eval_connection_layer(connection_layer cl, tensor input)
{
	tensor* output = (tensor*) malloc(sizeof(double)*cl.right_side);
	for (size_t i = 0; i < cl.right_side; i++){
		for (size_t j = 0; j < cl.left_side; j++)
			*output[i] = cl.weights[i][j];
		*output[i] += cl.biases[i];
	}
	return output;
}

void debug_cl(connection_layer cl)
{
	printf("  -connection layer %p:\n   [\n", &cl);
	printf("       weights");
	int padding = 10 * (int)cl.left_side - 6;
	for (int i = 0; i < padding; i++)printf(" ");
	printf("biases\n");
	for (size_t i = 0; i < cl.right_side; i++){
		printf("      ");
		print_double_arr(cl.weights[i], cl.left_side);
		printf(" %f\n", cl.biases[i]);
	}
	printf("    ]\n");
}