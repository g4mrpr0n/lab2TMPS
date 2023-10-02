#pragma once
#include <map>
#include "Book.h"
#include "InventoryAbstract.h"

class BookInventory: public InventoryAbstract
{
private:
	std::map<int, Book>BookMap; //map individual key to one book
	int BookCount[256]; //keep track of count of each book
	int lastIndex =-1;
	BookInventory() = default;
	static BookInventory* instancePtr;
public:
	
	BookInventory(const BookInventory& obj) = delete;
	static BookInventory* getInstance()
	{
		return instancePtr;
	}
	void addBook(Book book) override
	{
		bool exists = false;
		std::map<int, Book>::iterator i;
		for (i = BookMap.begin(); i != BookMap.end(); ++i) //see if the book already exists in the inventory
		{
			if (i->second.getName() == book.getName() && i->second.getAuthor() == book.getAuthor())
			{
				exists = true;
				break;
			}
		}
		if (exists)
		{
			BookCount[i->first]++;
			BookCount[i->first];
		}
		else { //otherwise add new book

			//check last nonzero index
			for (int i = 0; i <= 255; i++)
			{
				if (BookCount[i] > 0)
				{
					if (i == 255)
					{
						lastIndex = -1; // all entries are full
					}
					continue;
				}
				else if (BookCount[i] == 0)
				{
					lastIndex = i;
					break;
				}
			}
			
			//found last null entry
			if (lastIndex <= 255 && lastIndex != -1)
			{
				BookMap.insert({ lastIndex , book });
				BookCount[lastIndex]++;
			}
		}
	}
	Book findBook(int id) override
	{
		std::map<int, Book>::iterator it = BookMap.find(id);
	
		if (it != BookMap.end()) {
			Book foundBook = it->second;
			return foundBook;
		}
		else {
			Book::Builder builder1("", "");

			Book b1 = builder1.build();
			return b1;
		}
	}
	void removeBookCount(int id) override
	{
		BookCount[id]--;
	}
	std::map<int, Book> getBookMap() override 
	{ return BookMap; }
	int* getBookCount() override 
	{ return BookCount; }
	int getLastIndex() override
	{ return lastIndex; }

};
