#include "game.hpp"
#include "room.hpp"

Game::Game() {
	// NOTE: Keep in mind potential race condition with Item class?
	dialogueManagerInstance = DialogueManager::GetInstance();
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
		std::cout << '\n';
		dialogueManagerInstance->PrintDialogue();
		std::cout << '\n' << "> "; 
		input.Clear();
		std::cin >> input;
		while (!(std::cin.good())) {
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin >> input;
		}
		ParseInput();
	}
}

void Game::ParseInput() {
	dialogueManagerInstance->currentDialogue.Clear();
	if (input == "mvn") {
		MovePlayer(1);
	}
	else if (input == "mvs") {
		MovePlayer(2);
	}
	else if (input == "mve") {
		MovePlayer(3);
	}
	else if (input == "mvw") {
		MovePlayer(4);
	}
	else if (input == "quit") {
		exit(0);
	}
	else if (input == "help") {
		dialogueManagerInstance->currentDialogue = "CONTROLS:\n Move North - mvn \n Move East - mve \n Move South - mvs \n Move West - mvw \n Quit - quit" ;
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
		else {
			dialogueManagerInstance->currentDialogue = "You cannot move any further NORTH.";
		}
		break;
	// SOUTH
	case 2:
		if (player->ROWNUM != 7) {
			player->ROWNUM++;
			player->currentRoom = &(rooms[player->ROWNUM][player->COLNUM]);
		}
		else {
			dialogueManagerInstance->currentDialogue = "You cannot move any further SOUTH.";
		}
		break;
	// EAST	
	case 3:
		if (player->COLNUM != 7) {
			player->COLNUM++;
			player->currentRoom = &(rooms[player->ROWNUM][player->COLNUM]);
		}
		else {
			dialogueManagerInstance->currentDialogue = "You cannot move any further EAST.";
		}
		break;
	// WEST
	case 4:
		if (player->COLNUM != 0) {
			player->COLNUM--;
			player->currentRoom = &(rooms[player->ROWNUM][player->COLNUM]);
		}
		else {
			dialogueManagerInstance->currentDialogue = "You cannot move any further WEST.";

		}
		break;
	default: 
		break;
	}
}


