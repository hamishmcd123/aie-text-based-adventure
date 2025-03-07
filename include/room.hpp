#pragma once
#include "string.hpp"
#include "item.hpp"
#include "dialoguemanager.hpp"

namespace World {
	class Room {
	public:
		Item* item;
		Room();
		~Room();
		void Description(Item** itemArray) const;
		int COLNUM;
		int ROWNUM;
		static Core::DialogueManager* dialogueManagerInstance;
	private:
		String description;
	};
}




