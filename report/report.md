# Topic: *Creational Design Patterns*


## Author: Globa Georgeana

----

## Objectives:
&ensp; &ensp; __1. Study and understand the Creational Design Patterns.__

&ensp; &ensp; __2. Choose a domain, define its main classes/models/entities and choose the appropriate instantiation mechanisms.__

&ensp; &ensp; __3. Use some creational design patterns for object instantiation in a sample project.__

## Theory:
&ensp; &ensp; Creational design patterns are a category of design patterns that focus on the process of object creation. They provide a way to create objects in a flexible and controlled manner, while decoupling the client code from the specifics of object creation. Creational design patterns address common problems encountered in object creation, such as how to create objects with different initialization parameters, how to create objects based on certain conditions, or how to ensure that only a single instance of an object is created. There are several creational design patterns that have their own strengths and weaknesses. Each of it is best suited for solving specific problems related to object creation. By using creational design patterns, developers can improve the flexibility, maintainability, and scalability of their code.


## Implementation

This project is a Bookstore Management System, implemented in C++.

&ensp; The first design pattern - Singleton. Here is the modified version of `BookInventory.h`:
```cpp
class BookInventory: public InventoryAbstract
{
private:
	//...
	BookInventory() = default;
	static BookInventory* instancePtr;
public:
	
	BookInventory(const BookInventory& obj) = delete;
	static BookInventory* getInstance()
	{
		return instancePtr;
	}
	//...
}
```
The default constructer is now private and there is an instance pointer to get access to the instance. The copy constructer is deleted.

```cpp
//Source.cpp
BookInventory* BookInventory::instancePtr = new BookInventory();
```
==================================================================
&ensp; Afterwards, the Builder design pattern. Class `Book.h` now includes a `Builder` class that allows for customized book objects:

```cpp
class Book 
{public:
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
//...
}
```

```cpp
//Source.cpp
	Book::Builder builder1("Le big meowmeow", "Leon Jenkins");
	builder1.setYear(1999)
		.setGenre(fs) 
		.setPrice(50);

	Book b1 = builder1.build();
```
==================================================================

&ensp; Factory Method pattern. Admins and customers have customized payment rates for book purchases so here they are:
```cpp
class AdminPayment :public PaymentAbstract
{
public:
	AdminPayment() = default;
	float getRate() override
	{
		return 0.5;
	}
};

class CustomerPayment:public PaymentAbstract
{
public:
	CustomerPayment() = default;
	float getRate() override
	{
		return 1;
	}
};

class PaymentFactory:public PaymentFactoryAbstract
{
public:
	PaymentAbstract* getPaymentRate(std::string person) override
	{
		if (person == "Customer")
			return new CustomerPayment();
		else if (person == "Admin")
			return new AdminPayment();
	}
};

```
==================================================================

&ensp; Last pattern implemented is Prototype. It is used for the functionality of displaying a past purchase. `ShoppingCart.h`:

```cpp
class CartAbstract 
{
public:
	//..
	virtual CartAbstract* clone() const = 0;
}

class ShoppingCart: public CartAbstract
{
public:
	CartAbstract* clone() const override {
		return new ShoppingCart(*this);
	}
	//...
}
//...
CartAbstract *cart;

cart = c->clone();
```

## Conclusions / Screenshots / Results
In conclusion, implementing Creational design patterns offers extra flexibility for creating customized instances, and it is a very elegant and clever way to do so. It helps build maintainable and clean code, and they're really cool.