#include "main.h"
#include <stdbool.h>



simulator *new_simulator(size_t *shape, size_t shape_size, size_t width, size_t height)
{
	simulator *sim = (simulator*) malloc(sizeof(simulator));
	neural_network *nn = new_neural_network(shape, shape_size);
	game_board *gb = new_game_board(width, height);
	sim->nn = nn;
	sim->gb = gb;
	sim->time_survived = 0;
	return sim;
}

void simulator_step(simulator *sim)
{
	tensor input = nn_frame(sim->gb);
	direction dir = eval_neural_network(sim->nn, );
}

generation *new_generation(size_t snake_amount, 
													 size_t *shape,
													 size_t shape_size,
													 size_t width,
													 size_t height)
{
	generation *new_gen = (generation*) malloc(sizeof(generation));
	new_gen->simulators = (simulator**)  malloc(sizeof(simulator*)*snake_amount);
	for (size_t i = 0; i < snake_amount; i++)
		new_gen->simulators[i] = new_simulator(shape, shape_size, width, height);
	return new_gen;
}

void generation_step(generation *gen)
{
	//1. simuate game for all networks
	//2. kill half snakes
	//3. mutate snakes and add new snakes
}

int main(int argc, char argv[])
{
	int screen_size = 72*48;
	srand(time(0));
	size_t shape[5] = {screen_size*2, 500, 200, 50, 5};
	size_t shape_size = arr_size(shape);
	int show_layers = false;
	size_t network_amount = 2;
	neural_network **neural_nets = (neural_network**) malloc(sizeof(*new_neural_network)*network_amount);
	for (size_t i = 0; i < network_amount; i++)
	{
		neural_network *nn = new_neural_network(shape, shape_size);
		neural_nets[i] = nn;
	}
	for (size_t i = 0; i < network_amount; i++)
	{
		neural_network *nn = neural_nets[i];
		debug_nn(*nn, show_layers);
	}
	printf("created %lu neural_networks to play with\n", network_amount);
	play_game();
	printf("\n");
	return 0;
}