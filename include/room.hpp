#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ncurses.h>

#define ROOM_SIZE 5
// rooms are represented by a 5x5 square when printed, to adjust the character size all width are multiplied by two, the room size when printed is 5x10
#define ACCESS_COUNT 4

struct Coord2D {
	int x, y;
};

/*
 *	access points are defined in a array of four elements: X is current rooms, numbers represents the index of the neighbour.
 *	
 * 		0
 * 	  3 X 1
 * 		2
 * 
 */

class Room {

	private:

		Coord2D position = {-1, -1}; 
		// current position of the room in the arbitrary room grid, needed to print the room grid.
		bool is_access[ACCESS_COUNT] = {false}; 
		// if an element is false at index x, then wall x has no doors, thus no neighbour.
		Room* neighbours[ACCESS_COUNT] = {NULL};
		// access to the neighbours.
		
		std::string type = "Default";
		// type of the room, types are Default, Treasure, Shrine, Shop, Boss, Special

		int difficulty = 0; // temp attribute

	public:

		Room(bool access_layout[ACCESS_COUNT], std::string layout_type);
		Room(const Room& other);

		void print_room(WINDOW* win);

		void set_pos(Coord2D new_pos);

};

#endif
