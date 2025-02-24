#pragma once
#include "item.hpp"
#include "string.hpp"

namespace World {
	class Lamp : public Item {
	public:
		Lamp();
		void Description() const override;
		void Use() override;
		String description;
	private:
		bool turnedOn;
	};
}
