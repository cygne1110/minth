#include "../include/floor.hpp"

Floor::Floor() {

	load_floor();
	for(int i = 0; i < ROOM_GRID_SIZE; i++) {
		for(int j = 0; j < ROOM_GRID_SIZE; j++) {
			room_grid[i][j] = NULL;
		}
	}

}

Floor::Floor(int id) {

	load_floor(id);
	for(int i = 0; i < ROOM_GRID_SIZE; i++) {
		for(int j = 0; j < ROOM_GRID_SIZE; j++) {
			room_grid[i][j] = NULL;
		}
	}

}

Floor::~Floor() {

	for(int i = 0; i < ROOM_GRID_SIZE; i++) {
		for(int j = 0; j < ROOM_GRID_SIZE; j++) {
			if(room_grid[i][j] != NULL)
				delete room_grid[i][j];
		}
	}

}

void Floor::load_floor(int id, std::string filename) {

	std::ifstream file(filename);
	int id_temp, size_temp, difficulty_temp;
	std::string floor_name_temp;

	if(!file.is_open()) {
		std::cerr << "File " << filename << " could not be openened. Exiting...\n";
		exit(EXIT_FAILURE);
	}

	do {

		file >> id_temp >> floor_name_temp >> size_temp >> difficulty_temp;
		
	} while(!file.eof() && id != id_temp);

	if(file.eof()) {
		std::cerr << "Floor ID " << id << " doesn't exist. Exiting...";
		exit(EXIT_FAILURE);
	}

	size = size_temp;
	floor_name = floor_name_temp;
	difficulty = difficulty_temp;

	file.close();

}

void Floor::place_room(Room room, Coord2D pos) {

	room_grid[pos.y][pos.x] = new Room(room);
	room_grid[pos.y][pos.x]->set_pos(pos);

}

void Floor::print_floor(WINDOW* win) {

	for(int i = 0; i < ROOM_GRID_SIZE; i++) {
		for(int j = 0; j < ROOM_GRID_SIZE; j++) {
			if(room_grid[i][j] == NULL)
				continue; 
			room_grid[i][j]->print_room(win);
		}
	}

}