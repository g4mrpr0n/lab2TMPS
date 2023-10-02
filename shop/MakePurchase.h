#pragma once
#include "MakePurchaseAbstract.h"

class MakePurchase :public MakePurchaseAbstract
{
public:
	void purchase(CartAbstract *s, InventoryAbstract *b) override{
		std::map <int, Book> newMap = s->getShoppingCartMap();
		for (auto i = newMap.begin(); i != newMap.end(); ++i)
		{
			b->removeBookCount(i->first);
		}
		s->emptyShoppingCart();
	}
};

