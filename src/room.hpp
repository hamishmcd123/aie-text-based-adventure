#pragma once
#include "string.hpp"
#include "item.hpp"

namespace World {
	class Room : public Item {
	public:
		Item* item;
		Room();
		~Room();
		void Description() const override;
		int COLNUM;
		int ROWNUM;
	private:
		String description;
	};
}




