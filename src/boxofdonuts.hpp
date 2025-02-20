#pragma once
#include "item.hpp"

class BoxOfDonuts: public Item {
public:
	BoxOfDonuts();
	void Description() const override;
	void Use() override;
private:
	int count;
};