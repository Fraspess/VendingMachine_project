

#include <iostream>
#include <fstream>
#include "Drink.h"
using namespace std;

int main()
{
    string filename = "data.txt";
    string priceSave = "prices.txt";
    fstream data (filename);
    fstream prices(filename);
    
	VendingMachine vm;
    vm.loadPrices(priceSave);
    system("cls");
	//vm.showMenu();


	int mode;
    do {
        cout << "\nSelect mode ::\n1. Admin\n2. User\n0. Exit\nYour choice :: ";
        cin >> mode;

        if (mode == 1) 
        {
            system("cls");
            int adminChoice;
            do {
                cout << "\nAdmin mode ::\n1. Load ingredients\n2. Show status \n3. Change price\n4. Withdraw cash\n5. Show menu\n6. Show sells statistic \n0. Exit\nYour choice :: ";
                cin >> adminChoice;

                if (adminChoice == 1)
                {
                    system("cls");
                    int w, c, t, s;
                    cout << "Enter amount of water (ml), coffee (g), tea (g), sugar (g) :: ";
                    cin >> w >> c >> t >> s;
                    vm.loadIngredients(w, c, t, s);
                    cout << endl << endl << endl;
                    system("pause");
                    system("cls");
                }
                else if (adminChoice == 2) {
                    system("cls");
                    vm.showStatus();
                    cout << endl << endl << endl;
                    system("pause");
                    system("cls");
                }
                else if (adminChoice == 3) {
                    system("cls");
                    int drinkIndex;
                    double newPrice;
                    vm.showMenu();
                    cout << "Enter drink's number and new price :: ";
                    cin.ignore();
                    cin >> drinkIndex >> newPrice;
                    vm.changePrice(drinkIndex, newPrice);
                    vm.savePrices(priceSave);
                    cout << endl << endl << endl;
                    
                    system("pause");
                    system("cls");
                }
                else if (adminChoice == 4) 
                {
                    system("cls");
                    vm.getCashAmount();
                    int ammount;
                    cout << "How much usd ? " << endl;
                    cin >> ammount;
                    vm.withdrawCash(ammount);
                    cout << endl << endl << endl;
                    system("pause");
                    system("cls");
                }
                else if (adminChoice == 5)
                {
                    system("cls");
                    vm.showMenu();
                }
                else if (adminChoice == 6)
                {      
                    system("cls");
;                  vm.loadOrders(filename);
                    system("pause");
                    system("cls");
                }
            } while (adminChoice != 0);

        }
        else if (mode == 2) {
            system("cls");
            vm.loadOrders(filename);
            system("cls");
            int userChoice;
            do {
                cout << "\nUser mode ::\n1. Order drink\n0. Exit\nYour choice :: ";
                cin >> userChoice;

                if (userChoice == 1)
                {
                    system("cls");
                    vm.showMenu();
                    int drinkIndex;
                    cout << "Enter drink's number ::  ";
                    cin >> drinkIndex;
                    vm.orderDrink(drinkIndex);
                    vm.saveOrders(filename);
                    system("pause");
                    system("cls");
                    cout << endl << endl << endl;
                }
            } while (userChoice != 0);
        }
    } while (mode != 0);
    //vm.orderCountShow();



}





/*4.  Автомат гарячих напоїв. 
Створити ієрархію класів для подання гарячих напоїв Автомату(кава, чай, капучіно та ін.)
Створити програму для роботи Автомату у  режимах адмін та користувач
У режимі адміна передбачити 	
	Завантаження автомату водою, кава, чай, цукор
	Вивід статистики наявності складових для приготування напоїв
	Зміна цін на напої
	Вилучення кешу
У режимі користувача передбачити 		
Замовлення напою(+ оплата)	*/