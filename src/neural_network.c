#include "neural_network.h"


neural_network* new_neural_network(size_t *shape, size_t shape_size)
{
	neural_network* nn = (neural_network*) malloc(sizeof(neural_network));
	nn->shape_size = shape_size;
	nn->shape = shape;
	connection_layer* layer_connections= malloc(sizeof(connection_layer)*(shape_size-1));
	for (size_t i = 0; i < (shape_size - 1); i++)
	{
		size_t right_side  = shape[i];
		size_t left_side  = shape[i+1];
		layer_connections[i] = *new_connection_layer(right_side, left_side);
	}
	nn->layer_connections = layer_connections;
	return nn;
}

tensor eval_neural_network(neural_network *nn, tensor input)
{
	tensor* results = (tensor*) two_D_double_array(nn->shape_size, nn->shape[0]);
	results[0] = input;
	for (size_t i = 1; i < (nn->shape_size-1); i++)
		results[i] = *eval_connection_layer(nn->layer_connections[i], results[i-1]);
	return results[nn->shape_size-1];
} 


void debug_nn(neural_network nn, int show_layers)
{
	printf("neural net @ %p:\n", &nn);
	printf(" -shape %p:", nn.shape);
	print_size_arr(nn.shape, nn.shape_size);
	printf(" -%lu connection layers %p:\n", nn.shape_size - 1, nn.layer_connections);
	if (show_layers)
		for (size_t i = 0; i < nn.shape_size-1; i++)
			debug_cl(nn.layer_connections[i]);
}


void free_neural_net(neural_network *nn){
	free(&nn->shape);
	for (size_t i = 0; i < (nn->shape_size-1); i++)
		free_connection_layer(nn->layer_connections[i]);	
	free(&nn->shape_size);
	free(nn);
}