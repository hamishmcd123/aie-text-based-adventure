#pragma once
#include "string.hpp"
#include <list>
#include "room.hpp"

namespace Core {
class Player {
public:
	Player();
	~Player();
	bool FindSpell(String spell);
	World::Room* currentRoom;
	int COLNUM;
	int ROWNUM;
private:
	std::list<String> spells;
};

}
