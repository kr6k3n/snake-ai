#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "neural_network.h"
#include "snake.h"
#include "render_snake.h"
#define arr_size(x) (sizeof(x) / sizeof((x)[0]))

typedef struct simulator{
	game_board* gb;
	neural_network* nn;
	int time_survived;

} simulator;

typedef struct generation{
	simulator** simulators;
	size_t gen_size;
} generation;



void reset_simulator(simulator* sim);
simulator *new_simulator(size_t *shape, size_t shape_size, size_t width, size_t height);
generation *new_generation(size_t snake_amount, size_t *shape, size_t shape_size, size_t width, size_t height);
