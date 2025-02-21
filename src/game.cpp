#include "game.hpp"
#include "room.hpp"

Game::Game() {
	player = new Player;
	player->currentRoom = &(rooms[3][3]);
	player->COLNUM = 3;
	player->ROWNUM = 3;
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
		input.Clear();
		std::cin >> input;
		while (!(std::cin.good())) {
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin >> input;
		}
		std::cout << player->COLNUM;
		ParseInput();
	}
}

void Game::ParseInput() {
	if (input == "mvn") {
		MovePlayer(1);
	}
	else if (input == "mvs") {
		MovePlayer(2);
	}
	else if (input == "mve") {
		MovePlayer(3);
	}
	else if(input == "mvw") {
		MovePlayer(4);
	}

}

void Game::MovePlayer(int dir) {
	switch (dir) {
 
	// NORTH
	case 1:
		if (player->ROWNUM != 0) {
			player->ROWNUM--;
			player->currentRoom = &(rooms[player->ROWNUM][player->COLNUM]);
		}
		break;
	// SOUTH
	case 2:
		if (player->ROWNUM != 7) {
			player->ROWNUM++;
			player->currentRoom = &(rooms[player->ROWNUM][player->COLNUM]);
		}
		break;
	// EAST	
	case 3:
		if (player->COLNUM != 7) {
			player->COLNUM++;
			player->currentRoom = &(rooms[player->ROWNUM][player->COLNUM]);
		}

		break;
	// WEST
	case 4:
		if (player->COLNUM != 0) {
			player->COLNUM--;
			player->currentRoom = &(rooms[player->ROWNUM][player->COLNUM]);
		}
		break;
	default: 
		break;
	}
}


