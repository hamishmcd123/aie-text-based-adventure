#include "lamp.hpp"

Lamp::Lamp() : description(""){
	dialogueManagerInstance->GetInstance();
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

void Lamp::Use() {

	if (turnedOn == 0) {
		turnedOn = 1; 
		dialogueManagerInstance->currentDialogue = "You turn the lamp on.";
		description = "The lamp is on";
	}
	else {
		turnedOn = 0; 
		dialogueManagerInstance->currentDialogue = "You turned the lamp off. It's dark in here now.";
		description = "The lamp is off";
	}
}
