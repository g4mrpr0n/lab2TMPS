#pragma once
#include "CartAbstract.h"
#include "InventoryAbstract.h"


class MakePurchaseAbstract
{
public:
	virtual void purchase(CartAbstract* s, InventoryAbstract* b) = 0;
};

