#include <stdbool.h>
#include <stdlib.h>

#ifndef SNAKE
#define SNAKE

typedef enum {
	UP, DOWN, LEFT, RIGHT,
} direction;

typedef enum {
	GAME_OVER, OK,
} game_status;

typedef struct
{
	int x;
	int y;
} point;

typedef point food;

typedef struct point_list
{
	point* position;
	struct point_list* next;
} point_list;

typedef point_list snake;

typedef struct 
{
	size_t width;
	size_t height;
	food* food;
	snake* snake;
	size_t snake_size;
	direction snake_direction;
} game_board;

point *new_food(game_board *gb);
point_list *new_point_list(size_t size);

#endif