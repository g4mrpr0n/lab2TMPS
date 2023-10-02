#pragma once
#include "BookGenreAbstract.h"


class FictionGenre : public BookGenreAbstract
{
private:
	std::string description;
	int genreid = 1;
public:
	FictionGenre(std::string descriptions) :description(descriptions){}
	//inherited methods

	void changeDescription(std::string newDesc) override { this->description = newDesc; }
	int getGenreId() override { return genreid; }
	std::string getDescription() override { return description; }

	//new method not present in abs. class
	void fictionQuote()
	{ std::cout << "The difference between fiction and reality? Fiction has to make sense.\n"; }


	void printDescription() override { std::cout << "\n" << genreid << " " << description << "\nSpecial quote: "; fictionQuote(); }
};	

