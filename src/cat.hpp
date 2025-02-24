#pragma once
#include "item.hpp"

namespace World {
class Cat : public Item {
public:
	Cat();
	void Description() const override;
	void Use() override;
private:
	bool purring;
};
}
