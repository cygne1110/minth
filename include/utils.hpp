#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <ncurses.h>

WINDOW* create_newwin(int height, int width, int start_x, int start_y, bool border);

void destroy_win(WINDOW *local_win);

void terminate();

void signal_handler(int sig);

#endif