#pragma once
#include <stdlib.h>
#include "room.hpp"
#include "player.hpp"
#include <iostream>
#include "string.hpp"
#include "dialoguemanager.hpp"
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
private:
	Room rooms[8][8]; 
	Player* player;
};