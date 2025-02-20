#include "game.hpp"
#include "room.hpp"

Game::Game() {
	player = new Player;
	player->currentRoom = &(rooms[3][3]);
	
	// Initialise Room Numbers/Positions 
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			rooms[i][j].COLNUM = i;
			rooms[i][j].ROWNUM = j;
		}
	}
}

Game::~Game() {
	delete player;
}

void Game::DrawRooms() {
	for (int i = 0; i < 8; i++) {
		std::cout << '\n';
		for (int j = 0; j < 8; j++) {
			// Draw room symbol depending on what item is in there...
			if (&(rooms[i][j]) == player->currentRoom) {
				std::cout << " [O] ";
			}
			else if (rooms[i][j].item == nullptr) {
				std::cout << " [ ] ";
			}
			else {
				std::cout << " [ ] ";
			}
		}
	}
}


void Game::Run() {
	while (true) {
		system("cls");
		DrawRooms();
		std::cout << '\n' << "> "; 
		std::cin >> input;
	}
}


void Game::UpdatePlayerPos() {
}

//void Game::MovePlayer(int dir) {
//	switch (dir) {
//
//	case 1:
//
//
//	case 2:
//
//
//	case 3:
//
//
//	case 4:
//		
//	}
//}
