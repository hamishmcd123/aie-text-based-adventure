#pragma once
#include "string.hpp"

class Spell {
public:
	int damage;
	String name;
	Spell(String name, int damage); 
	void Cast();
	static bool Compare(Spell a, Spell b); 
};