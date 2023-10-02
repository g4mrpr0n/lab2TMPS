#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <conio.h>
#include "InventoryDisplay.h"
#include "BookInventory.h"
#include "FictionGenre.h"
#include "MakePurchase.h"
#include "ShoppingCart.h"
#include "ViewShoppingCart.h"
#include "Book.h"
#include "PaymentFactory.h"

BookInventory* BookInventory::instancePtr = new BookInventory();


int main()
{
	BookInventory* Inventory = BookInventory::getInstance();

	char step1;
	int choice;

	PaymentFactoryAbstract* factory = new PaymentFactory();
	PaymentAbstract* paymentMethod = factory->getPaymentRate("Customer");

	InventoryAbstract *inv;
	inv = Inventory;

	BookGenreAbstract* fs;
	FictionGenre f("Fiction is certainly not Non-Fiction. It is very non-serious.");
	fs = &f;

	CartAbstract* c, *cart;
	ShoppingCart s;
	cart = new ShoppingCart();
	c = &s;

	Book::Builder builder1("Le big meowmeow", "Leon Jenkins");
	builder1.setYear(1999)
		.setGenre(fs) 
		.setPrice(50);

	Book b1 = builder1.build();


	Book::Builder builder2("The bright tomorrow", "Anan Poopy");
	builder2.setYear(2020)
		.setGenre(fs) 
		.setPrice(100);

	Book b2 = builder2.build();

	Book::Builder builder3("Hello world!", "Alex Mamia");
	builder3.setYear(2009)
		.setGenre(fs) // Replace with the appropriate genre object
		.setPrice(60);

	Book b3 = builder3.build();

	Book::Builder builder4("Programmer jokes", "Tom Dandy");
	builder4.setYear(1997)
		.setGenre(fs) // Replace with the appropriate genre object
		.setPrice(70);

	Book b4 = builder4.build();

	Book::Builder builder5("Le big meowmeow", "Leon Jenkins");
	builder5.setYear(1999)
		.setGenre(fs) // Replace with the appropriate genre object
		.setPrice(50);

	Book b5 = builder5.build();

	inv->addBook(b1); 
	inv->addBook(b2);
	inv->addBook(b3);
	inv->addBook(b4);
	inv->addBook(b5);

	std::string mainMenuClient = "Welcome to Bookstore Management system!\nChoose the option next to the action you want to take.\n\nInventory:\n1. Find Books\n2. Show all books\n\nGenre:\n3. Show Fiction description\n\nShop:\n4. Add book to shopping cart\n5. View shopping cart\n6. Proceed with purchase\n7. View last purchase\n\n"; 
	std::string menuExtra= "\n(ADMIN ONLY)\n7. Add new Book to Inventory\n8. Change description for Fiction\n\n";
	std::cout << "Welcome to Bookstore Management system!\nPress 'c' if you're a client and 'a' if you're an admin.\n";
	std::cin >> step1;

	

	while (true)
	{
		system("cls");
		if (step1 == 'c')
		{
			std::cout << mainMenuClient;
		}
		else if (step1 == 'a')
		{
			paymentMethod = factory->getPaymentRate("Admin");
			std::cout << mainMenuClient + menuExtra;
		}
		std::cin >> choice;
		
		switch(choice)
		{
			case 1:
			{	
				unsigned int bookid;
				std::cout << "Enter book ID:\n";
				std::cin >> bookid;
				Book b = inv->findBook(bookid);
				if (b.getPrice() > 0) {
					std::cout << "Found the book:\n" << b.getName() << " " << b.getAuthor() << " " << b.getYear() << " " << b.getGenre()->getGenreId() << " " << b.getPrice() << "\n";
				}
				else {
					std::cout << "\nBook doesn't exist in our inventory.\n";
				}
				_getch();
				break;
			}
			case 2:
			{	
				InventoryDisplayAbstract* displayb;
				InventoryDisplay display;
				displayb = &display;

			displayb->printInventory(inv);
			_getch();
			break;
			}
			case 3:
			{	fs->printDescription();
			_getch();
			break;
			}
			case 4:
			{	unsigned int bookid;
				std::cout << "Enter book ID:\n";
				std::cin >> bookid;
				c->addBookCart(inv, bookid);
				_getch();
				break;
			}
			case 5:
			{	ViewShoppingCart v;
			ViewShoppingCartAbstract *view;
			view = &v;
				
				view->printShoppingCart(c);

				_getch();
				break;
			}
			case 6:
			{	std::cout << "Your total is: ";

			if (step1 == 'c')
			{
				std::cout << c->calculateTotal() * paymentMethod->getRate() << "since you're a client.";
			}
			else { std::cout << c->calculateTotal() * paymentMethod->getRate() << " since you're an admin."; }


			cart = c->clone();

			MakePurchase m;
			MakePurchaseAbstract* makepurchase;
			makepurchase = &m;
			makepurchase->purchase(c, inv);
			_getch();
			break;
			}

			case 7:
			{
				ViewShoppingCart v;
				ViewShoppingCartAbstract* view;
				view = &v;
				
				view->printShoppingCart(cart);
				_getch();
				break;
			}
			case 8:
			{	if (step1 == 'c') { break; }
			std::cout << "Input the name, author, year and price of the book:\n";
			std::string name, author;
			unsigned int year, price;
			std::cin.ignore();
			std::getline(std::cin, name);
			std::getline(std::cin, author);
			std::cin >> year >> price;
			Book::Builder builder6(name, author);
			builder6.setYear(year)
				.setGenre(fs)
				.setPrice(price);

			Book b6 = builder6.build();
			Inventory->addBook(b6);
			_getch();
			break;
			}
			case 9:
			{	if (step1 == 'c') { break; }
			std::cout << "Enter the new description for Fiction\n";
			std::string description;
			std::cin.ignore();
			std::getline(std::cin, description);
			fs->changeDescription(description);
			_getch();
			break;
			}
		}
	}
}