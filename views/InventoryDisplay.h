#pragma once
#include "InventoryDisplayAbstract.h"

class InventoryDisplay :public InventoryDisplayAbstract
{
public:
	void printInventory(InventoryAbstract* b) override
	{
		std::map<int, Book> newMap = b->getBookMap();
		for (auto i = newMap.begin(); i != newMap.end(); ++i)
			std::cout << "\n\n" << i->first << ": "  << b->getBookCount()[i->first] << " " << i->second.getName() << " " << i->second.getAuthor() << " " << i->second.getGenre()->getGenreId() << " " << i->second.getPrice() << " " << i->second.getYear() << "\n";
	}
};

