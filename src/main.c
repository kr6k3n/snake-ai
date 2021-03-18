#include "main.h"
#include <stdbool.h>

int main(int argc, char argv[])
{
	size_t screen_size = 17*17;
	srand(time(0));
	int show_layers = false;

	size_t snake_amount = 10;
	size_t shape[5] = {screen_size*2, 
					   screen_size,
					   screen_size/2,
					   screen_size/4,
					   5};
	size_t shape_size = arr_size(shape);	
	size_t width  = 17;
	size_t height = 17;
	generation *test_gen = new_generation(snake_amount, shape, shape_size, width, height);
	//play_game();
	for (size_t i = 0; i < 10; i++)
	{
		printf("generation step: %lu\n", i+1);
		generation_step(test_gen);
	}
	printf("\n");
	test_folder();
	return 0;
}


// size_t network_amount = 1000;
// neural_network **neural_nets = (neural_network**) malloc(sizeof(neural_network*)*network_amount);
// for (size_t i = 0; i < network_amount; i++)
// {
// 	neural_network *nn = new_neural_network(shape, shape_size);
// 	neural_nets[i] = nn;
// }
// for (size_t i = 0; i < network_amount; i++)
// {
// 	neural_network *nn = neural_nets[i];
// 	debug_nn(*nn, show_layers);
// }
// printf("created %lu neural_networks to play with\n", network_amount);
