#include "../include/utils.hpp"

WINDOW* create_newwin(int height, int width, int start_x, int start_y, bool border) {

	WINDOW *local_win;

	local_win = newwin(height, width, start_x, start_y);
	if(border) {
		for(int i = 0; i < height; i++) {
			mvwprintw(local_win, i, 0, "█");
			mvwprintw(local_win, i, 1, "█");
			mvwprintw(local_win, i, width-2, "█");
			mvwprintw(local_win, i, width-1, "█");
		}
		for(int i = 0; i < width; i++) {
			mvwprintw(local_win, 0, i, "█");
			mvwprintw(local_win, height-1, i, "▒");
			mvwprintw(local_win, height-2, i, "█");
		}
	}
	wrefresh(local_win);

	return local_win;

}

void destroy_win(WINDOW *local_win) {

	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);

}

void terminate() {

	endwin();
	std::cout << "Exiting...\n";

}

void signal_handler(int sig) {

	std::cerr << "Program stopped from signal " << sig << ".\n";
	terminate();
	exit(EXIT_FAILURE);

}
