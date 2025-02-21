#pragma once
#include <stdlib.h>
#include <ctime>
#include "room.hpp"
#include "player.hpp"
#include <iostream>
#include "string.hpp"
#include "dialoguemanager.hpp"
#include "lamp.hpp"
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
	Item* itemArray[3]; 
private:
	Room rooms[8][8]; 
	Player* player;
};