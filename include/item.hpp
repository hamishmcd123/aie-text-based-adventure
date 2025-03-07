#pragma once
#include "string.hpp"
#include "dialoguemanager.hpp"

namespace World {
class Item {
public:
	virtual ~Item();
	virtual void Description() const;
	virtual void Use();
	static Core::DialogueManager* dialogueManagerInstance;
};
}
