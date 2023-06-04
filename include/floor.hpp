#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "room.hpp"

#define ROOM_GRID_SIZE 7
// room grid is represented by a 7x7 square of rooms.

class Floor {

	private:

		Room* room_grid[ROOM_GRID_SIZE][ROOM_GRID_SIZE];

		int difficulty;
		int size;

		std::string floor_name;

	public:

		Floor();
		Floor(int id);
		~Floor();

		void load_floor(int id = 0, std::string filename = "./data/floors.dat");
		void place_room(Room room, Coord2D pos);
		void print_floor(WINDOW* win);

};

#endif