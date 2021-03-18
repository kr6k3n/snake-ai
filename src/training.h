#include "snake.h"
#include "neural_network.h"
#include <math.h>
#include "render_snake.h"

#ifndef TRAINING
#define TRAINING

typedef struct simulator{
	game_board* gb;
	neural_network* nn;
	int time_survived;
	tensor current_frame;
	tensor past_frame;
} simulator;

typedef struct generation{
	simulator** simulators;
	size_t gen_size;
} generation;



void reset_simulator(simulator* sim);
simulator *new_simulator(size_t *shape, size_t shape_size, size_t width, size_t height);
extern generation *new_generation(size_t snake_amount, size_t *shape, size_t shape_size, size_t width, size_t height);
tensor merge_frames(tensor current_frame, tensor past_frame, size_t frame_size);
extern void generation_step(generation *gen);

#endif