#pragma once
#include "item.hpp"
class Lamp : public Item {
public:
	Lamp();
	void Description() const override;
	void Use() override;
private:
	bool turnedOn; 
};