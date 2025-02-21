#pragma once
#include "string.hpp"
#include <list>
#include "room.hpp"
class Player {
public:
	Player();
	~Player();
	bool FindSpell(String spell);
	Room* currentRoom;
	int COLNUM;
	int ROWNUM;
private:
	std::list<String> spells;
};