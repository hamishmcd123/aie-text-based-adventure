#pragma once
#include "string.hpp"
#include "dialoguemanager.hpp"

namespace World {
class Spell {
public:
	int damage;
	String name;
	Spell(String name, int damage); 
	void Cast();
	Spell();
	static bool Compare(Spell a, Spell b);
	static Core::DialogueManager* dialogueManagerInstance;
};
}
