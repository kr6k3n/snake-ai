#include "snake.h"


point *new_food(game_board *gb)
{
  point* new_point = (point*) malloc(sizeof(point));
  new_point->x = rand() % (gb->width - 1);
  new_point->y = rand() % (gb->height - 1);
  return new_point;
}

point_list *new_point_list(size_t size)
{
  point_list* head = (point_list*) malloc(sizeof(point_list));
  point* headpoint = (point*) malloc(sizeof(point));
  head->position = headpoint;
  if (size == 1){
    head->next = NULL;
    return head;
  }
  head->next = new_point_list(size-1);
  return head;
}

bool same_point(point *p1, point *p2){
  return (p1->x == p2->x) && (p1->y == p2->y);
}
/*
 *  Initializes game_board
 */
game_board *new_game_board(size_t width, size_t height)
{
  game_board* new_board = (game_board*) malloc(sizeof(game_board));
  new_board->width = width;
  new_board->height = height;

  new_board->snake_size = 2;
  new_board->snake_direction = UP;

  snake* new_snake = new_point_list(2);
  int snake_x = width / 2;
  int snake_y = height / 2;
  //assign positions
    new_snake->position->x = snake_x;
    new_snake->position->y = snake_y;
    new_snake->next->position->x = snake_x;
    new_snake->next->position->y = snake_y-1;
  new_board->snake = new_snake;

  new_board->food = new_food(new_board);
  free(snake_x);
  free(snake_y);
  return new_board;
}
/*
 *  Simulate time step and returns a game status
 */
game_status time_step(game_board *gb, direction direction)
{
  //determine next head position
  point *new_head = (point*) malloc(sizeof(point));
  new_head->x = gb->snake->position->x;
  new_head->x = gb->snake->position->y;
  switch (direction)
  {
    case UP:
      new_head->y--;break;
    case DOWN:
      new_head->y++;break;
    case LEFT:
      new_head->x--;break;
    case RIGHT:
      new_head->x++;break;
  }
  //check for border colisions
  if  (  new_head->x < 0 
      || new_head->y < 0 
      || new_head->x >= gb->width 
      || new_head->y >= gb->height)
        return GAME_OVER;
  //check for self eating snake
  snake* snake_ptr= gb->snake;
  while (snake_ptr->next){
    snake_ptr = snake_ptr->next;
    if (same_point(gb->snake->position, snake_ptr->position))
      return GAME_OVER;
  }

  //attach beginning to snake
  point_list *new_elem = new_point_list(1);
  new_elem->position = new_head;
  new_elem->next = gb->snake;
  gb->snake = new_elem;

  if (same_point(new_head, gb->food))
    //eat food
    gb->food = new_food(gb);
  else{
    //delete tail
    snake *new_tail = gb->snake;
    while (new_tail->next->next)
      new_tail = new_tail->next;
    free(new_tail->next);
    new_tail->next = NULL;
  }
  return OK;
}