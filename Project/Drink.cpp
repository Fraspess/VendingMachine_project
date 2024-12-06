#include "Drink.h"
#include <string>


void VendingMachine::loadIngredients(const int& water, const int& coffee, const int& tea, const int& sugar)
{
	this->water += water;
	this->coffee += coffee;
	this->tea += tea;
	this->sugar += sugar;
	cout << "Ingridients have loaded succsecfully " << endl;
}

void VendingMachine::showStatus() const
{
	cout << "\t\t Water :: " << water << endl;
	cout << "\t\t Coffee :: " << coffee << endl;
	cout << "\t\t Tea :: " << tea << endl;
	cout << "\t\t Sugar :: " << sugar << endl;
	cout << "\t\t Cash :: " << cash << endl;
	cout << endl << endl;
}

void VendingMachine::changePrice(const int& drinkIndex, const double& newPrice)
{
	if (drinkIndex >= 1 && drinkIndex <= 5)
	{
		drinks[drinkIndex - 1].price = newPrice;
		cout << "Price for " << drinks[drinkIndex - 1].name << " has changed to " << newPrice << " USD" << endl;
	}
	else
	{
		cout << "Error! Drink hasn't found !" << endl;
	}
}

void VendingMachine::withdrawCash(const int& amount)
{
	cout << cash << " usd in the machine " << endl;
	if (amount > cash)
	{
		cout << "Not enough cash in the machine " << endl;
		return;
	}
	cout << amount << " has been withdrawn from vending machine" << endl;
	cash = cash - amount;
}

void VendingMachine::orderDrink(const int& drinkNumber)
{
	if (drinkNumber < 0 || drinkNumber > 5)
	{
		cout << "Drink wasn't found " << endl;
		return;
	}
	Drink& drink = drinks[drinkNumber - 1];
	if (water < drink.waterRequired || coffee < drink.coffeeRequired || tea < drink.teaRequired || sugar < drink.sugarRequired)
	{
		cout << "Not enough ingredients for making drink " << endl;
		return;
	}
	cout << "Price for  " << drink.name << " is " << drink.price << " usd . Please insert cash " << endl;
	double payment;
	std::cin >> payment;

	double change = payment - drink.price;
	if (payment >= drink.price)
	{
		water -= drink.waterRequired;
		coffee -= drink.coffeeRequired;
		tea -= drink.teaRequired;
		sugar -= drink.sugarRequired;
		cash += drink.price;
		cout << "Your " << drink.name << " is ready! Change :: " << change << " usd" << endl;
		orderCount[drinkNumber - 1]++;
	}
	else
	{
		cout << "Insufficient funds! Try again " << endl;
	}


}

//void VendingMachine::showMenu() const
//{
//	cout << "\t\t\t\t\t\tAvaivable drinks " << endl;
//	for (size_t i = 0; i < 5; i++)
//	{
//		cout << "" << i + 1 << ".\t" << drinks[i].name << " - " << drinks[i].price << " usd" << endl;
//		cout << "-----------\t------------------";
//		cout << endl;
//	}
//}


//void VendingMachine::showMenu() const
//{
//	cout << "\n\t\t\t\t\t\t-------------------------------\n";
//	cout << "\t\t\t\t\t\t|   Available Drinks Menu    |\n";
//	cout << "\t\t\t\t\t\t-------------------------------\n";
//	cout << "\n\t\t\t\t\t\tPlease choose a drink:\n";
//	cout << "\t\t\t\t\t\t-------------------------------\n";
//	cout << "\n";
//
//	for (size_t i = 0; i < 5; i++)
//	{
//		cout << "\t\t\t\t\t\t" << i + 1 << ". " << drinks[i].name << " - " << drinks[i].price << " USD\n";
//		cout << "\t\t\t\t\t\t  - Water Required: " << drinks[i].waterRequired << " ml\n";
//		cout << "\t\t\t\t\t\t  - Coffee Required: " << drinks[i].coffeeRequired << " g\n";
//		cout << "\t\t\t\t\t\t  - Tea Required: " << drinks[i].teaRequired << " g\n";
//		cout << "\t\t\t\t\t\t  - Sugar Required: " << drinks[i].sugarRequired << " g\n";
//		cout << "\t\t\t\t\t\t-------------------------------\n";
//	}
//	cout << "\n\t\t\t\t\t\t-------------------------------\n";
//	cout << "\t\t\t\t\t\t* Please select a drink by entering the number *\n";
//	cout << "\t\t\t\t\t\t-------------------------------\n";
//	cout << endl;
//}

void VendingMachine::showMenu() const
{
	cout << "\n-------------------------------\n";
	cout << "|   Available Drinks Menu    |\n";
	cout << "-------------------------------\n";
	cout << "\nPlease choose a drink:\n";
	cout << "-------------------------------\n";
	cout << "\n";

	for (size_t i = 0; i < 5; i++)
	{
		cout << "" << i + 1 << ". " << drinks[i].name << " - " << drinks[i].price << " USD\n";
		cout << "  - Water Required: " << drinks[i].waterRequired << " ml\n";
		cout << "  - Coffee Required: " << drinks[i].coffeeRequired << " g\n";
		cout << "  - Tea Required: " << drinks[i].teaRequired << " g\n";
		cout << "  - Sugar Required: " << drinks[i].sugarRequired << " g\n";
		cout << "-------------------------------\n";
	}
	cout << "\n-------------------------------\n";
	cout << "* Please select a drink by entering the number *\n";
	cout << "-------------------------------\n";
	cout << endl;
}

















void VendingMachine::getCashAmount() const
{
	cout << cash << " usd in the machine " << endl;
}

void VendingMachine::loadOrders(const string& filename)
{
	std::ifstream loadFile;
	loadFile.open(filename, std::ios_base::app);
	if (!loadFile.is_open())
	{
		cout << "Error opening file " << endl;
		return;
	}

	for (size_t i = 0; i < 5; ++i)
	{
		orderCount[i] = 0;
	}

	string drinkName;
	string test;
	int count;
	size_t loadedDrinks = 0;
	while (loadFile >> drinkName)
	{
		loadFile >> test >> test;
		loadFile >> count;
		loadFile >> test;

		if (drinks[loadedDrinks].name == drinkName)
		{
			orderCount[loadedDrinks] = count;
		}
		cout << "----------------------------------------------------------------------------" << endl;
		cout << drinks[loadedDrinks].name << " was ordered " << orderCount[loadedDrinks] << " times " << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		loadedDrinks++;

	}

	loadFile.close();


}


void VendingMachine::saveOrders(const string& filename)
{
	std::ofstream saveFile;
	saveFile.open(filename/*,std::ios_base::app*/);
	if (!saveFile.is_open())
	{
		cout << "Error opening file" << endl;
		return;
	}
	for (size_t i = 0; i < 5; i++)
	{
		saveFile << drinks[i].name << " was ordered " << orderCount[i] << " times " << endl;
	}
	saveFile.close();
}

void VendingMachine::orderCountShow()
{
	cout << "rfaf" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << orderCount[i] << endl;
	}
}

void VendingMachine::savePrices(const string& filename)
{
	std::ofstream saveFile;
	saveFile.open(filename);
	if (!saveFile.is_open())
	{
		cout << "Error opening file " << endl;
		return;
	}
	for (size_t i = 0; i < 5; i++)
	{
		saveFile << drinks[i].price << endl;
	}
	saveFile.close();
}

void VendingMachine::loadPrices(const string& filename)
{
	std::ifstream loadFile;
	loadFile.open(filename);
	if (!loadFile.is_open())
	{
		cout << "Error opening file " << endl;
		return;
	}
	int loadPrices;
	for (size_t i = 0; i < 5; i++)
	{
		loadFile >> loadPrices;
		drinks[i].price = loadPrices;
	}

	cout << "Loaded prices sucaiofa" << endl;
	loadFile.close();
}

