#include "render_snake.h"

void display_points(snake* snake, const chtype symbol) {
  while(snake) {
    mvaddch(snake->position->y, snake->position->x, symbol);
    snake = snake->next;
  }
}

direction get_next_move(direction previous) {
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

int **nn_frame(game_board *gb)
{
  int **frame = two_D_int_array(gb->height, gb->width);
  snake *snake_ptr = gb->snake;
  do {
    frame[snake_ptr->position->y][snake_ptr->position->x];
    snake_ptr = snake_ptr->next;
  }  while (snake_ptr->next);
  return frame;
}