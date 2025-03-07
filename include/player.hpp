#pragma once
#include "string.hpp"
#include "room.hpp"
#include "spell.hpp"
#include <cmath>
#include <vector>

namespace Core {
class Player {
public:
	Player();
	~Player();
	bool FindSpell(String spell);
	World::Room* currentRoom;
	int COLNUM;
	int ROWNUM;
	std::vector<World::Spell> knownSpells; 
private:
	std::vector<String> spells;
};

}
