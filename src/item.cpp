#include "../include/item.hpp"
using namespace World; 
Core::DialogueManager* Item::dialogueManagerInstance = Core::DialogueManager::GetInstance();

Item::~Item() {}

void Item::Use() {}

void Item::Description() const {}