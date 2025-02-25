#pragma once
#include "item.hpp"
#include "string.hpp"

namespace World {
class Cat : public Item {
public:
	Cat();
	void Description() const override;
	void Use() override;
	String description;
private:
	bool purring;
};
}
