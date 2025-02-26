#include "player.hpp"

using namespace Core;

Player::Player() : spells{ "Eclipse", "Eruption", "Frostbite","Levitate","Mirage","Petrify","Polymorph","Teleport","Thunderwave","Vortex", "banban"} {}

Player::~Player() {}


// Assume std::vector<String> spells is sorted...
bool Player::FindSpell(String spell) {
	int L = 0;
	int R = spells.size() - 1;
	while (L <= R) {
	int M = (int)((L + R) / 2); 
		if (spells[M] == spell) {
			return 1;
		}
		if (spells[M] < spell) {
			L = M + 1;
		}
		if (!(spells[M] < spell)) {
			R = M - 1;
		}
	}
	return 0;
	}
