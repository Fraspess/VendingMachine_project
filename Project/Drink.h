#pragma once
#include <iostream>
#include <fstream>
using std::string;
using std::cout;
using std::endl;
class Drink
{
public:
	std::string name;
	double price;
	int waterRequired;
	int coffeeRequired;
	int teaRequired;
	int sugarRequired;


	Drink()
		:name(""),price(0),waterRequired(0),coffeeRequired(0),teaRequired(0),sugarRequired(0)
	{
	}

	Drink(string name, double price, int water, int coffee, int tea, int sugar)
		:name(name),price(price),waterRequired(water),coffeeRequired(coffee),teaRequired(tea),sugarRequired(sugar)
	{

	}
};



class VendingMachine :public Drink
{
private:
	Drink drinks[5];
	int orderCount[5]{};
	int water, tea, coffee, sugar, cash;
public:
	VendingMachine()
		:water(1000),coffee(500),tea(500),sugar(500),cash(0)
	{
		drinks[0] = Drink("Coffee", 10.0, 100, 50, 0, 5);
		drinks[1] = Drink("Tea", 8.0, 100, 0, 50, 3);
		drinks[2] = Drink("Americano", 15.0, 100, 50, 0, 2);
		drinks[3] = Drink("Cappucino", 15.0, 100, 50, 0, 5);
		drinks[4] = Drink("Espresso", 10.0, 100, 50, 0, 1);
	}
	void loadIngredients(const int& water, const int& coffee, const int& tea, const int& sugar);
	void showStatus()const;
	void changePrice(const int& drinkIndex,const double& newPrice);
	void withdrawCash(const int& amount);
	void orderDrink(const int& drinkNumber);
	void showMenu()const;
	void getCashAmount()const;
	void loadOrders(const string& filename);
	void saveOrders(const string& filename);
	void orderCountShow();
	void savePrices(const string& filename);
	void loadPrices(const string& filename);
};

