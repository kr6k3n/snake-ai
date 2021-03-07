#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

#ifndef  CONNECTION_LAYER
#define  CONNECTION_LAYER

//data structures
typedef double weight;
typedef double bias;
typedef double *tensor;

typedef struct
{
	size_t left_side;
	size_t right_side;
	bias *biases;
	weight **weights;
} connection_layer;
//utils
extern void debug_cl(connection_layer cl);
extern double init_weight();
extern tensor rand_tensor();
//real stuff
extern connection_layer *new_connection_layer(size_t left_side, size_t right_side);
extern tensor *eval_connection_layer(connection_layer cl, tensor input);
#endif