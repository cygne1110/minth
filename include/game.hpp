#ifndef GAME_HPP
#define GAME_HPP

#include "./floor.hpp"
#include "./utils.hpp"

#include <cstdlib>
#include <clocale>
#include <signal.h>

class Game {

	private:

		Floor current_floor;

		int layout_count;
		std::vector<Room> layouts;

	public:

		Game();

		void load_layouts(std::string filename = "./data/layout.dat");
		void new_floor(int floor_id);
		void print_game();
		void initialize();
		void play();

};

#endif