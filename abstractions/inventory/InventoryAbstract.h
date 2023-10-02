#pragma once
#include "Book.h"
#include <map>
#include <iostream>

class InventoryAbstract
{
public:
	virtual void addBook(Book book) = 0;
	virtual Book findBook(int id) = 0;
	virtual void removeBookCount(int id) = 0;
	virtual std::map<int, Book> getBookMap() = 0;
	virtual	int* getBookCount() = 0;
	virtual int getLastIndex() = 0;
};

