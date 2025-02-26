#pragma once
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include "room.hpp"
#include "player.hpp"
#include "string.hpp"
#include "dialoguemanager.hpp"
#include "lamp.hpp"
#include "cat.hpp"
#include "boxofdonuts.hpp"

namespace Core {
		class Game {
		public:
			Game();
			~Game();
			void Run();
			void DrawRooms();
			String input;
			DialogueManager* dialogueManagerInstance;
			void MovePlayer(int dir);
			void ParseInput();
			int seed;
			void RoomDescription();
			enum gamestates {
				NORMAL,
				SPELLCASTING
			};
		enum gamestates currentState;
			World::Item* itemArray[3];
		private:
			World::Room rooms[8][8];
			Player* player;
		};
}
