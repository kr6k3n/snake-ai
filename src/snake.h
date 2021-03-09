#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef SNAKE
#define SNAKE

typedef enum direction{
	UP, DOWN, LEFT, RIGHT,
} direction;

typedef enum game_status{
	GAME_OVER, OK,
} game_status;

typedef struct point
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

typedef struct game_board
{
	size_t width;
	size_t height;
	food* food;
	snake* snake;
	size_t snake_size;
	direction snake_direction;
} game_board;

extern point *new_food(game_board *gb);
extern point_list *new_point_list(size_t size);
extern game_board *new_game_board(size_t width, size_t height);
extern game_status time_step(game_board *gb, direction direction);
extern void debug_game_board(game_board *gb);
extern void debug_snake(snake *s);
#endif