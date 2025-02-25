#pragma once
#include "item.hpp"
#include "string.hpp"

namespace World {
class BoxOfDonuts: public Item {
public:
	BoxOfDonuts();
	void Description() const override;
	void Use() override;
	String description;
	// This is necessary to use sprintf. 
	// itoa is NOT defined in the C-standard
	// https://cplusplus.com/reference/cstdlib/itoa/
	char buff[50]; 
private:
	int count;
};
}
