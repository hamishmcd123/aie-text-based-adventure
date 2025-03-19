#pragma once
#include "room.hpp"
#include "player.hpp"
#include "string.hpp"
#include "dialoguemanager.hpp"
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
				SPELLCASTING,
				SPELLFINDING
			};
		enum gamestates currentState;
			World::Item* itemArray[3];
			void RoomCheck(); 
		private:
			World::Room rooms[8][8];
			Player* player;
			bool toExit; 
		};
}
