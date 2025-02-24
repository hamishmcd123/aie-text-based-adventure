#include "dialoguemanager.hpp"

using namespace Core;

DialogueManager* DialogueManager::instance = nullptr;
String DialogueManager::currentDialogue = "Type \"help\" to view the controls.";
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