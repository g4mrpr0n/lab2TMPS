#pragma once
#include <iostream>
class BookGenreAbstract
{
public:
	BookGenreAbstract(){}
	virtual void printDescription() = 0;
	virtual void changeDescription(std::string newDesc) = 0;
	virtual int getGenreId() =0;
	virtual std::string getDescription() =0;
};

