#include "lamp.hpp"

Lamp::Lamp() : description(""){
	turnedOn = (rand() % 2);
	if (turnedOn == 1) {
		description = "The lamp is on";
	}
	else {
		description = "The lamp is off";
	}
}


void Lamp::Description() const {
	dialogueManagerInstance->currentDialogue = description;
}

void Lamp::Use() {}
