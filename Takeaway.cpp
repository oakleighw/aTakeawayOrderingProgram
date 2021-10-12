/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	cout << "Welcome to the TakeawayOrderingSystem3000 , please type 'help' for a list of commands" << endl;
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");
	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << menu.toString() << endl;
		}
		else if (command.compare("add") == 0)
		{
			Item* choice; //choice parameter as an item pointer
			vector<Item*> menuItems = menu.getMenuItems(); //get menu items
			int number; //number of choice

			//add item to order based on selection (parameters 1+)
			for (int i = 1; i < parameters.size(); i++)
			{
				number = std::stoi(parameters[i]);//convert choice to int
				number--; //reduce by 1

				//check to see if choice is in the menu, else throw an error
				try {
					menu.checkMenu(number);
				}
				catch (int &e)
				{ //let user know there was an error if choice isn't in the menu
					cout << "Error " << e << " Occured" << endl;
					cout << "Returning to order selection \n" << endl;
					parameters.clear();
					continue;
				}
				choice = menuItems[number];//assign the choice as the menu item
				order.add(choice); //add choice to order
				cout << choice->getName() << " added to order!" << endl;			
				//calculate total
				order.calculateTotal();
			}
			cout << "Please type 'checkout' to view current order" << endl;
		}
		else if (command.compare("remove") == 0)
		{
			int choice;//choice parameter as an int
			vector<Item*> orderItems = order.getOrderItems(); //get order items
			vector<int> choices; //vector of indexes to remove

			//check if order is empty
			if (orderItems.size()==0)
			{
				cout << "Cannot remove items from an empty order!" <<endl;
				parameters.clear();
				continue;
			}

			//for each choice parameter
			for (int i = 1; i < parameters.size(); i++)
			{
				choice = std::stoi(parameters[i]);//convert choice to int
				choices.push_back(choice);//push choice into choices array
			}	

			//sort choices in descending order, to avoid repositioning when removing from orderItems vector
			std::sort(choices.begin(), choices.end(), std::greater<>());

			for (int i = 0; i < (choices.size()); i++)//for each choice in choices vector
			{
				choice = choices[i];//assign the choice as the order item
				//check to see if choice is in the order, else throw an error
				try {
					order.checkOrder(choice-1);
				}
				catch (int& e)
				{ 
					//let user know there was an error if choice isn't in the order
					cout << "Error " << e << " Occured" << endl;
					cout << "Returning to order selection \n" << endl;
					parameters.clear();
					continue;
				}
				cout << orderItems[choice-1]->getName() << " removed from order!" << endl;
				order.remove(choice); //remove choice from order	

				//calculate total
				order.calculateTotal(); 
			}
			cout << "Please type 'checkout' to view current order" << endl;
			parameters.clear();
		}
		else if (command.compare("checkout") == 0)
		{
			//display order summary
			cout << order.toString() << endl;
			cout << "Do you want to place your order?" << endl;
			cout << "Type 'y' to confirm or 'n' to go back and modify it" << endl;

			std::string orderConfirm;
			getline(cin, orderConfirm); //get answer

			//convert to character for switch statement. Also allows for "yes" or "no" answers
			char orderCon = orderConfirm[0]; 

			switch (orderCon)
			{
				case 'y':  
					//print receipt
					order.printReceipt();
					cout << "Receipt Printed!" << endl;
					//exit program
					userCommand = "exit"; 
					break;
				case 'n':
					parameters.clear(); //return to selecting items
					cout << "Back to order selection..." << endl;
					break;
				case 'e':
					//exit program
					userCommand = "exit";
					break;
				default:     //else return to checkout if answer is incorrect
					cout << "unidentified answer, taking you back to checkout...";
					continue;
			}
		}
		else if (command.compare("help") == 0)
		{
			cout << "menu - displays the menu" << endl;
			cout << "add [Menu Item number] - add an item to the order based on its menu number" << endl;
			cout << "remove [Order Item number] - remove an item from your order based on its order number" << endl;
			cout << "checkout - display the items in your order, the price, and discount savings" << endl;
			cout << "help - display a help menu" << endl;
			cout << "exit - terminate the program" << endl;
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();

}