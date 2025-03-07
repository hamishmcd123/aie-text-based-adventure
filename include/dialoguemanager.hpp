#pragma once
#include "string.hpp"
namespace Core {
class DialogueManager {
public:
	static String currentDialogue;
	static DialogueManager* instance; 
	static DialogueManager* GetInstance();
	static void PrintDialogue();
private:
	DialogueManager();
};
}
