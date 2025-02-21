#pragma once
#include <stdlib.h>
#include "room.hpp"
#include "player.hpp"
#include <iostream>
#include <tuple>
#include "string.hpp"
class Game {
public:
	Game();
	~Game();
	void Run();
	void DrawRooms();
	String input;
	void MovePlayer(int dir);
	void ParseInput();
private:
	Room rooms[8][8]; 
	Player* player;
};