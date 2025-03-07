#include "../include/boxofdonuts.hpp"

using namespace World; 

BoxOfDonuts::BoxOfDonuts() {
	count = (rand() % 5) + 1;  
	char buff[50];
	sprintf(buff, "There are %d donuts.", count);
	description = buff;
}

void BoxOfDonuts::Description() const {
	dialogueManagerInstance->currentDialogue = description;
}

void BoxOfDonuts::Use() {
	if (count > 0) {
		count--; 
		char buff[50];
		sprintf(buff, "There are now %d donuts.", count);
		description = buff;
		dialogueManagerInstance->currentDialogue = "You eat a donut.";
	}
	else {
		description = "There are no more donuts."; 
		dialogueManagerInstance->currentDialogue = "There are no more donuts to eat. You ate them all. Shame on you.";
	}

}