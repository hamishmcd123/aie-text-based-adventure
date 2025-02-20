#pragma once
#include "item.hpp"

class Cat : public Item {
public:
	Cat();
	void Description() const override;
	void Use() override;
private:
	bool purring;
};
