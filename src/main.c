#include "main.h"
#include <stdbool.h>

int main(int argc, char argv[])
{
	int screen_size = 72*48*2;
	srand(time(0));
	size_t shape[5] = {screen_size, 500, 200, 50, 5};
	size_t shape_size = arr_size(shape);
	neural_network *nn = new_neural_network(shape, shape_size);
	int show_layers = false;
	debug_nn(*nn, show_layers);
	return 0;
}