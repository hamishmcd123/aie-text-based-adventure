#include "../include/room.hpp"

using namespace World;

Core::DialogueManager* Room::dialogueManagerInstance = Core::DialogueManager::GetInstance();

Room::Room() {
	item = nullptr;
}

Room::~Room() {}
void Room::Description() const {
	if (item != nullptr) {
		item->Description();
	}
	else {
	dialogueManagerInstance->currentDialogue = "The room is empty.";
	}
}

