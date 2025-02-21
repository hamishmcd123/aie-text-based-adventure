#pragma once
#include "string.hpp"
#include "dialoguemanager.hpp"

class Item {
public:
	virtual void Description() const;
	virtual void Use();
	static	DialogueManager* dialogueManagerInstance;
};