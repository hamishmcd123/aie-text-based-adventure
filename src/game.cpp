#include "game.hpp"

using namespace Core; 

Game::Game() {
currentState = NORMAL;
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

	itemArray[0] = new World::Lamp;
	itemArray[1] = new World::Cat;
	itemArray[2] = new World::BoxOfDonuts;

	for (World::Item* i : itemArray) {
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
	for (World::Item* i : itemArray) {
		delete i;
	}
	delete player;
	delete dialogueManagerInstance;
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
			else if (rooms[i][j].item == itemArray[1]) {
				std::cout << " [C] ";
			}
			else if (rooms[i][j].item = itemArray[2]) {
				std::cout << " [D] ";
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
		if (currentState == NORMAL) {
			input.Clear();
			std::cin >> input;
			while (!(std::cin.good())) {
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::cin >> input;
			}
			ParseInput();
			}
		else if (currentState == SPELLFINDING) {
			input.Clear();
			String tempspell; 
			std::cin >> tempspell;
				while (!(std::cin.good())) {
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::cin >> tempspell;
			}
				if (player->FindSpell(tempspell)) {
					dialogueManagerInstance->currentDialogue = "You know that spell.";
				}
				else {
					dialogueManagerInstance->currentDialogue = "You don't know that spell. ";
				}
			currentState = NORMAL;
		}
		else if (currentState = SPELLCASTING) {
			input.Clear();
			String tempspell;
			std::cin >> tempspell;
				while (!(std::cin.good())) {
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::cin >> tempspell;
			}
				if (player->FindSpell(tempspell)) {
					for (int i = 0; i < player->knownSpells.size(); i++) {
						if (player->knownSpells[i].name == tempspell) {
							player->knownSpells[i].Cast();
						}
					}
				}
				else {
					dialogueManagerInstance->currentDialogue = "Spell not found";
				}
				currentState = NORMAL;

		}
	}
}

void Game::RoomDescription() {
		player->currentRoom = &(rooms[player->ROWNUM][player->COLNUM]);
		// Could probably put inside something...
		if (player->currentRoom->item == itemArray[0]) {
			(*itemArray[0]).Description();
		}
		else if (player->currentRoom->item == itemArray[1]) {
			(*itemArray[1]).Description();
		}
		else if (player->currentRoom->item == itemArray[2]) {
			(*itemArray[2]).Description();
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
		dialogueManagerInstance->currentDialogue = "CONTROLS:\n Move North - mvn \n Move East - mve \n Move South - mvs \n Move West - mvw \n Room Description - desc \n Use - use \n Look Up Spell - spell \n Cast Spell - cast \n Quit - quit";
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
	else if (input == "spell") {
		dialogueManagerInstance->currentDialogue = "Enter a spell name: ";
		currentState = SPELLFINDING;
	}
	else if (input == "cast") {
		dialogueManagerInstance->currentDialogue = "Enter a spell to cast: ";
		currentState = SPELLCASTING; 
	}
	else {
		dialogueManagerInstance->currentDialogue = "Unknown command.";
	}
}
void Game::RoomCheck() {
	if (player->currentRoom->item == itemArray[0]) {
		dialogueManagerInstance->currentDialogue = "There is a lamp in the room. It looks old."; 
	}
	else if (player->currentRoom->item == itemArray[1]) {
		dialogueManagerInstance->currentDialogue = "There is a cat in the room. What a head."; 

	}
	else if (player->currentRoom->item == itemArray[2]) {
		dialogueManagerInstance->currentDialogue = "There is a box of donuts in the room.";
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
	RoomCheck();
}

	