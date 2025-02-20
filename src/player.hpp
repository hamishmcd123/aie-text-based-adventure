#pragma once
#include "string.hpp"
#include <list>
#include "room.hpp"
#include <vector>
class Player {
public:
	Player();
	~Player();
	bool FindSpell(String spell);
	Room* currentRoom;
	std::vector<int> pos;
private:
	std::list<String> spells; 
};