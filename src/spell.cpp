#include "spell.hpp"

using namespace World;

Core::DialogueManager* Spell::dialogueManagerInstance = Core::DialogueManager::GetInstance(); 

Spell::Spell(String name, int damage) : name(name), damage(damage){}

Spell::Spell() {}

void Spell::Cast() {
	// Insane hack do not look at.
	char namebuff[20];
	char buff[100];
	for (int i = 0; i < name.Length(); i++) {
		namebuff[i] = name[i]; 
	}
	namebuff[name.Length()] = '\0';
	sprintf(buff, "You casted %s. It dealt %d damage", namebuff, damage);
	dialogueManagerInstance->currentDialogue = buff; 
	
}
