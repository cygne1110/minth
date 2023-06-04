#include "../include/room.hpp"


Room::Room(bool access_layout[ACCESS_COUNT], std::string layout_type) {

	type = layout_type;
	for(int i = 0; i < ACCESS_COUNT; i++)
		is_access[i] = access_layout[i];

}

Room::Room(const Room& other) {

	position = other.position;
	for(int i = 0; i < ACCESS_COUNT; i++) {
		is_access[i] = other.is_access[i];
		neighbours[i] = other.neighbours[i];
	}
	type = other.type;
	difficulty = other.difficulty;

}

void Room::print_room(WINDOW* win) {

	int offset_x = position.x * ROOM_SIZE + 2;
	int offset_y = position.y * 2 * ROOM_SIZE + 4;
	
	const char full_wall[] 	= "██████████";
	const char up_door[] 	= "████  ████";
	const char side_wall[] 	= "██      ██";
	const char right_wall[] = "        ██";
	const char left_wall[] 	= "██        ";
	const char empty[] 		= "          ";

	mvwprintw(win, offset_x, offset_y, is_access[0] ? up_door : full_wall);
	mvwprintw(win, offset_x + 1, offset_y, side_wall);
	if(is_access[1]) {
		if(is_access[3])
			mvwprintw(win, offset_x + 2, offset_y, empty);
		else
			mvwprintw(win, offset_x + 2, offset_y, left_wall);
	} else {
		if(is_access[3])
			mvwprintw(win, offset_x + 2, offset_y, right_wall);
		else
			mvwprintw(win, offset_x + 2, offset_y, side_wall);
	}
	mvwprintw(win, offset_x + 3, offset_y, side_wall);
	mvwprintw(win, offset_x + 4, offset_y, is_access[2] ? up_door : full_wall);

}

void Room::set_pos(Coord2D new_pos) {

	position.x = new_pos.x;
	position.y = new_pos.y;

}
