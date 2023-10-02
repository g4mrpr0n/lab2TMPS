#pragma once
#include "ViewShoppingCartAbstract.h"

class ViewShoppingCart : public ViewShoppingCartAbstract
{
public:
	void printShoppingCart(CartAbstract* s) override
	{
		std::cout << "Items in your cart are the following: \n";
		std::map<int, Book> newMap = s->getShoppingCartMap();
		for (auto i = newMap.begin(); i != newMap.end(); ++i)
			std::cout << "\n" << i->first << ": " << i->second.getName() << " " << i->second.getAuthor() << " " << i->second.getGenre()->getGenreId() << " " << i->second.getPrice() << " " << i->second.getYear() << "\n";
	}
};

