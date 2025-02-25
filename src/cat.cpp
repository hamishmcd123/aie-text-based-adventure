#include "cat.hpp"

using namespace World; 

Cat::Cat() {
	purring = (rand() % 2);
	if (purring == true) {
		description = "The cat is purring.";
	}
	else {
		description = "The cat is not purring.";
	}
}

void Cat::Use() {
	if (purring == false) {
		purring = true;
		description = "The cat is purring";
		dialogueManagerInstance->currentDialogue = "You pet the cat. It begins to purr."; 
	}
	else {
		dialogueManagerInstance->currentDialogue = "You pet the cat. It continues to purr.";
	}
}


void Cat::Description() const {
	dialogueManagerInstance->currentDialogue = description;
}
