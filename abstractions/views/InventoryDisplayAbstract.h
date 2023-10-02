#pragma once
#include "InventoryAbstract.h"

class InventoryDisplayAbstract
{
public:
	virtual void printInventory(InventoryAbstract* b) = 0;
};

