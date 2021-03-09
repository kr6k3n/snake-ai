#include <stdio.h>
#include <stdlib.h>
#include "connection_layer.h"
#include "utils.h"

#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

//constants
#define MUTATION_CHANCE 1E-2

typedef struct {
	size_t *shape;
	size_t shape_size;
	connection_layer *layer_connections; 
} neural_network;

//utils functions
extern double sigmoid(double x);
extern void debug_nn(neural_network nn, int show_layers);
//NN IMPORTANT functions
//neural network
extern neural_network *new_neural_network(size_t *shape, size_t shape_size);
extern tensor eval_neural_network(neural_network nn, tensor input);
#endif