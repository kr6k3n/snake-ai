#include "render_snake.h"

//display game using ncurses
void display_game(game_board *gb)
{
  clear_screen();
  snake* snake_ptr = gb->snake;
  //render snake
  while(snake_ptr) {
    mvaddch(snake_ptr->position->y, snake_ptr->position->x, '#');
    snake_ptr = snake_ptr->next;
  }
  //render food
  mvaddch(gb->food->y, gb->food->x, 'o');
  //render borders
  for (size_t i = 0; i < gb->width; i++)
    mvaddch(gb->height, i, '_');
  for (size_t i = 0; i < gb->height; i++)
    mvaddch(i, gb->width, '|');  
  refresh_screen();
}

//gets input from keyboard
direction get_next_move(direction previous)
{
  int ch = getch();
  switch (ch) {
    case KEY_LEFT:
      if (previous != RIGHT) return LEFT;
    case KEY_RIGHT:
      if (previous != LEFT) return RIGHT;
    case KEY_DOWN:
      if (previous != UP) return DOWN;
    case KEY_UP:
      if (previous != DOWN) return UP;
    default:
      return previous;
  }
}

//renders game into a (1,1) tensor
tensor nn_frame(game_board *gb)
{
  tensor frame = (tensor) malloc(sizeof(double) * gb->width * gb->height);
  snake *snake_ptr = gb->snake;
  do {
      size_t index = gb->width * snake_ptr->position->y + snake_ptr->position->x;
      frame[index] = 1;
    snake_ptr = snake_ptr->next;
  }  while (snake_ptr->next);
  size_t food_index = gb->width * gb->food->y + gb->food->x;
  if (frame[food_index])
    frame[food_index] = 2;
  else
    frame[food_index] = 1;
  return frame;
}

//user game loop
void play_game(){
	//game test
	init_ncurses();
	game_board *gb = new_game_board(17, 15);
	debug_game_board(gb);
	direction dir = get_next_move(gb->snake_direction);
  bool not_lost = true;
	while(not_lost){
		//printf("snake pos: %d, %d\n", gb->snake->position->x, gb->snake->position->y);
		dir = get_next_move(dir);
		game_status stat = time_step(gb, dir);
		display_game(gb);
		if (stat == GAME_OVER){
			stop_ncurses();
			usleep(5E5);
			printf("game_over\n");
			not_lost = false;
		}
		usleep(5E4);
	}
}