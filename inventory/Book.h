#pragma once
#include <string>
#include "BookGenreAbstract.h"


class Book 
{
private:
	
	BookGenreAbstract* genre;
	std::string name;
	std::string author;
	int year;
	int price;
	Book() = default;
	Book(std::string name, std::string author, int year, BookGenreAbstract* genre, int price) :
		name(name), author(author), year(year), genre(genre), price(price) {}
public:
	
    class Builder {
    private:
        BookGenreAbstract* genre = nullptr;
        std::string name;
        std::string author;
        int year = 0;
        int price = 0;

    public:
        Builder(std::string name, std::string author)
            : name(name), author(author) {}

        Builder& setGenre(BookGenreAbstract* genre) {
            this->genre = genre;
            return *this;
        }

        Builder& setYear(int year) {
            this->year = year;
            return *this;
        }

        Builder& setPrice(int price) {
            this->price = price;
            return *this;
        }

        Book build() {
            return Book(name, author, year, genre, price);
        }
    };

    BookGenreAbstract* getGenre() { return genre; }
    std::string getName() { return name; }
    std::string getAuthor() { return author; }
    int getYear() { return year; }
    int getPrice() { return price; }

};