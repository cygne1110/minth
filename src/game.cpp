#include "../include/game.hpp"

Game::Game() {

	load_layouts();

}

void Game::load_layouts(std::string filename) {
	
	std::ifstream file(filename);
	bool is_access_temp[ACCESS_COUNT];
	std::string type_temp;

	if(!file.is_open()) {
		std::cerr << "File " << filename << " could not be openened. Exiting...\n";
		exit(EXIT_FAILURE);
	}

	file >> layout_count;

	for(int i = 0; i < layout_count; i++) {

		file >> type_temp;
		for(int j = 0; j < ACCESS_COUNT; j++)
			file >> is_access_temp[j];
		
		layouts.push_back(Room(is_access_temp, type_temp));
		
	}	

	file.close();

}

void Game::new_floor(int floor_id) {

	current_floor.load_floor(floor_id);

}

void Game::print_game() {


	int floor_win_height = ROOM_SIZE * ROOM_GRID_SIZE + 5;
	int floor_win_width = ROOM_SIZE * ROOM_GRID_SIZE * 2 + 8;
	WINDOW* floor_win = create_newwin(floor_win_height, floor_win_width, 5, 10, true);

	current_floor.print_floor(floor_win);

	wrefresh(floor_win);
	wmove(floor_win, 0, 0);
	wgetch(floor_win);

	destroy_win(floor_win);

}

void Game::initialize() {

	if(atexit(terminate) != 0) {
		std::cerr << "Couldn't initialize cleaning routines. Exiting...\n";
		exit(EXIT_FAILURE);
	}

	struct sigaction action;
  	action.sa_handler = signal_handler;
  	sigemptyset(&action.sa_mask);
  	action.sa_flags = 0;

	if (sigaction(SIGINT, &action, NULL) != 0) {
		std::cerr << "Couldn't initialize signal handling for SIGINT. Exiting...\n";
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGSEGV, &action, NULL) != 0) {
		std::cerr << "Couldn't initialize signal handling for SIGSEGV. Exiting...\n";
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGTERM, &action, NULL) != 0) {
		std::cerr << "Couldn't initialize signal handling for SIGTERM. Exiting...\n";
		exit(EXIT_FAILURE);
	}

}

void Game::play() {

	initialize();

	setlocale(LC_ALL, "");
	initscr();

	current_floor.place_room(layouts[2], {0, 0});
	for(int i = 0; i < 5; i++) {
		current_floor.place_room(layouts[4], {i, i+1});
		current_floor.place_room(layouts[9], {i+1, i+1});
	}
	current_floor.place_room(layouts[4], {5, 6});
	current_floor.place_room(layouts[3], {6, 6});

	print_game();

	endwin();

}