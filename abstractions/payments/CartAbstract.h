#pragma once
#include "InventoryAbstract.h"


class CartAbstract 
{
public:
	CartAbstract() {};
	virtual void addBookCart( InventoryAbstract* i,int id )=0;
	virtual int calculateTotal() =0;
	virtual std::map<int, Book> getShoppingCartMap() = 0;
	virtual void emptyShoppingCart()= 0;

	virtual CartAbstract* clone() const = 0;

};

