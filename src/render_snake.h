#include "snake.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#ifndef RENDER
#define RENDER

#define init_ncurses() ({\ 
              initscr();\
              cbreak();\
              noecho();\
              keypad(stdscr, TRUE);\
              curs_set(0);\
              timeout(100);\
            })

#define stop_ncurses() endwin()
#define clear_screen() clear()
#define refresh_screen() refresh()

extern direction get_next_move(direction previous);
extern void display_points(snake *snake, const chtype symbol);

#endif