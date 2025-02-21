#include "game.hpp"

Game::Game() {
 seed = std::time(NULL);
 std::srand(seed);
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

	itemArray[0] = new Lamp;
	itemArray[1] = nullptr;
	itemArray[2] = nullptr;

	for (Item* i : itemArray) {
		int temprow = rand() % 7;
		int tempcol = rand() % 7;
		while (rooms[temprow][tempcol].item != nullptr) {
			int temprow = rand() % 7;
			int tempcol = rand() % 7;
		}
		rooms[temprow][tempcol].item = i; 
	}
}

Game::~Game() {
	delete player;
	delete[] itemArray; 
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
			else if (rooms[i][j].item == itemArray[0]) {
				std::cout << " [L] ";
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

void Game::RoomDescription() {
	Room currentRoom = rooms[player->ROWNUM][player->COLNUM];
		// Could probably put inside something...
		if (currentRoom.item == itemArray[0]) {
			(*itemArray[0]).Description();
		}
		else {
			dialogueManagerInstance->currentDialogue = "The room is empty.";
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
		dialogueManagerInstance->currentDialogue = "CONTROLS:\n Move North - mvn \n Move East - mve \n Move South - mvs \n Move West - mvw \n Room Description - desc \n Quit - quit";
	}
	else if (input == "seed") {
		// should be big enough for the forseeable future...
		char buff[50];
		sprintf(buff, "Seed: %d", seed);
		dialogueManagerInstance->currentDialogue = buff;
	}
	else if (input == "desc") {
		RoomDescription();
	}
	else if (input == "use") {
		if (rooms[player->ROWNUM][player->COLNUM].item != nullptr) {
			rooms[player->ROWNUM][player->COLNUM].item->Use();
		}
		else {
			dialogueManagerInstance->currentDialogue = "There is nothing to use.";
		}
	}
	else if (input == "banban") {
		dialogueManagerInstance->currentDialogue = "smash";
	}
	else {
		dialogueManagerInstance->currentDialogue = "Unknown command.";
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


