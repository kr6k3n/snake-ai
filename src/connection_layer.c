#include "connection_layer.h"
double sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

tensor rand_tensor(size_t tensor_size)
{
	tensor result = (tensor) malloc(sizeof(double)*tensor_size);
	for (size_t i = 0; i < tensor_size; i++)
		result[i] = rand1();    
	return result;
}

connection_layer *new_connection_layer(size_t left_side, size_t right_side){
	connection_layer *cl = (connection_layer *)malloc(sizeof(connection_layer));
	cl->left_side = left_side;
	cl->right_side = right_side;
	//init weights
	cl->weights = (weight**) two_D_double_array(right_side, left_side);
	for (size_t i = 0; i < right_side; i++)
		for (size_t j = 0; j < left_side; j++)
			cl->weights[i][j] = rand1();
	//init biases
	double* biases = (double *)malloc(sizeof(double) * right_side);
	for (size_t i = 0; i < right_side; i++)
		biases[i] = rand1();
	cl->biases = biases;

	return cl;
}

tensor *eval_connection_layer(connection_layer *cl, tensor input)
{
	print_double_arr(input, cl->left_side);
	printf("\n input\n");
	tensor output = (tensor) malloc(sizeof(double)*cl->right_side);
	for (size_t i = 0; i < cl->right_side; i++){
		for (size_t j = 0; j < cl->left_side; j++)
			output[i] += cl->weights[i][j] * input[j];
		output[i] += cl->biases[i];
		output[i] = sigmoid(output[i]);
		//print_double_arr(_output, cl->right_side);
	}
	tensor * _output = &output;
	return _output;
}

void debug_cl(connection_layer *cl)
{
	printf("  -connection layer %p:\n   [\n", &cl);
	printf("       weights");
	int padding = 10 * (int)cl->left_side - 6;
	for (int i = 0; i < padding; i++)printf(" ");
	printf("biases\n");
	for (size_t i = 0; i < cl->right_side; i++){
		printf("      ");
		print_double_arr(cl->weights[i], cl->left_side);
		printf(" %f\n", cl->biases[i]);
	}
	printf("    ]\n");
}

void free_connection_layer(connection_layer* con)
{
	free(con->biases);
	for (size_t i = 0; i < con->right_side; i++)
		free(con->weights[i]);
	free(con->weights);
	free(&con->left_side);
	free(&con->right_side);
	free(con);
}