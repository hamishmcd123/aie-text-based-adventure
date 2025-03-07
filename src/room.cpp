#include "../include/room.hpp"

using namespace World;

Core::DialogueManager* Room::dialogueManagerInstance = Core::DialogueManager::GetInstance();

Room::Room() {
	item = nullptr;
}

Room::~Room() {}
void Room::Description(Item** itemArray) const {
	for (int i = 0; i < 3; i++) {
		if (item == itemArray[i]) {
			itemArray[i]->Description();
			return;
		}
		else {
			continue;
		}
	}
	dialogueManagerInstance->currentDialogue = "The room is empty.";
}

