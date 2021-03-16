#include "training.h"


double gaussian()
{
		double r = rand1();
		return exp(-exp2((r-5E-1)/5E-2));
}


void mutate(neural_network* nn)
{
	for (size_t i = 0; i < (nn->shape_size-1); i++){
		connection_layer *con = &nn->layer_connections[i];
		for (size_t j = 0; j < con->right_side; j++){
			for (size_t k = 0; k < con->left_side; k++){
					con->weights[j][k] = con->weights[j][k] * (1-gaussian());
			}
		}
	}
}


simulator *new_simulator(size_t *shape, size_t shape_size, size_t width, size_t height)
{
	simulator *sim = (simulator*) malloc(sizeof(simulator));
	neural_network *nn = new_neural_network(shape, shape_size);
	sim->nn = nn;
	game_board *gb = new_game_board(width, height);
	sim->gb = gb;
	sim->time_survived = 0;
	sim->current_frame = (tensor) malloc(sizeof(double)*width*height*2);
	for (size_t i = 0; i < width*height*2; i++)
		sim->current_frame[i] = 0;
	sim->past_frame = sim->current_frame;
	return sim;
}

tensor merge_frames(tensor current_frame, tensor past_frame, size_t frame_size)
{
	tensor _merged = (tensor) malloc(sizeof(double)*frame_size*2);
	for (size_t i = 0; i < frame_size*2; i+=2){
		_merged[i] = current_frame[i];
		_merged[i+1] = past_frame[i+1];
	}
	return _merged;
}
game_status simulator_step(simulator *sim)
{
	size_t frame_size = sim->gb->width*sim->gb->height;
	tensor input = merge_frames(sim->current_frame, sim->past_frame, frame_size);
	tensor *nn_output;
	nn_output = eval_neural_network(sim->nn, &input);
	size_t output_size = sim->nn->shape[sim->nn->shape_size-1];
	direction dir = get_max_index(*nn_output, output_size);
	game_status stat = time_step(sim->gb, dir);
	if (stat == OK)
		sim->time_survived = sim->time_survived + 1;
	return stat;
}

generation *new_generation(size_t gen_size, 
						   size_t *shape,
						   size_t shape_size,
						   size_t width,
						   size_t height)
{
	generation *new_gen = (generation*) malloc(sizeof(generation));
	new_gen->simulators = (simulator**) malloc(sizeof(simulator*)*gen_size);
	new_gen->gen_size = gen_size;
	for (size_t i = 0; i < gen_size; i++)
		new_gen->simulators[i] = new_simulator(shape, shape_size, width, height);
	return new_gen;
}

int score(simulator *s) {
	return exp2(s->gb->snake_size * s->time_survived) + s->time_survived;
	//(self.length*self.time)**2 + self.time
}

int compare_simulators(simulator *s1, simulator *s2)
{
	return score(s1)-score(s2);
}

void generation_step(generation *gen)
{
	//1. simuate game for all networks
	printf("gen_size %lu\n", gen->gen_size);
	for (size_t i = 0; i < gen->gen_size; i++){
		//simulate snake while alive
		while (simulator_step(gen->simulators[i]))
			continue;
	}
	//2. kill half snakes
	//sort them by score
	printf("sorted scores : \n");
	int (*compar)(simulator *s1, simulator *s2);
    compar = &compare_simulators;
	qsort(gen->simulators, gen->gen_size, sizeof(simulator*), compar);
	for (size_t i = 0; i < gen->gen_size; i++)
		printf("score: %d\n", score(gen->simulators[i]));
	
	//3. mutate snakes and add new snakes
}