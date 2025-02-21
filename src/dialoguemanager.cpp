#include "dialoguemanager.hpp"
DialogueManager* DialogueManager::instance = nullptr;
String DialogueManager::currentDialogue = "balls";
DialogueManager::DialogueManager() {}


DialogueManager* DialogueManager::GetInstance() {
	if (DialogueManager::instance == nullptr) {
		instance = new DialogueManager; 
		return instance;
}
	else {
		return instance;
	}
}

void DialogueManager::PrintDialogue() {
	std::cout << currentDialogue;
}