#include "player.hpp"

using namespace Core;

Player::Player() : spells{ "Eclipse", "Eruption", "Frostbite","Levitate","Mirage","Petrify","Polymorph",
"Teleport","Thunderwave","Vortex", "banban" }, knownSpells(11) {

	knownSpells[0]=(World::Spell(spells[0], 20)); // Eclipse
	knownSpells[1] =(World::Spell(spells[1], 50)); // Eruption
	knownSpells[2] = (World::Spell(spells[2], 30)); // Frostbite
	knownSpells[3] = (World::Spell(spells[3], 0)); // Levitate
	knownSpells[4] =(World::Spell(spells[4], 0)); //	Mirage
	knownSpells[5] = (World::Spell(spells[5], 0)); // Petrify
	knownSpells[6] =(World::Spell(spells[6], 0)); // Polymorph
	knownSpells[7] =(World::Spell(spells[7], 0)); // Teleport
	knownSpells[8] =(World::Spell(spells[8], 30)); // Thunderwave
	knownSpells[9] =(World::Spell(spells[9], 40)); // Vortex
	knownSpells[10] =(World::Spell(spells[10], 100000000)); // banban
}
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
