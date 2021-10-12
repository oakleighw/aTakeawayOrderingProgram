#include "Order.h"
#include "Appetiser.h"
#include <iostream>
#include <fstream>

//order destructor
Order::~Order() {}
//adds an item pointer to the order
void Order::add(Item* _item) 
{
	this->items.push_back(_item);
}

//check if choice selected is within Order
void Order::checkOrder(int _OrderNumber)
{
	if (_OrderNumber >= this->items.size() || _OrderNumber < 0)
	{
		std::cout << "An Item was not found" << std::endl;
		throw 404; //throw error if item not found
	}
}

void Order::remove(int _position) 
{
	--_position; //minus 1 for 0 indexing of vector
	this->items.erase(items.begin() + _position); //remove item based on index
}

std::vector<Item*> Order::getOrderItems()
{
	return this->items;
}

float Order::getSavings()
{
	return this->savings;
}
std::string Order::getSavingsString()
{
	std::string stringSavings = std::to_string(this->savings);//convert to string
	return "\x9C" + stringSavings.substr(0, (stringSavings.size() - 4));//remove trailing 0's
}

std::string Order::getTotalString()
{
	//convert to string and remove trailing float zeros
	std::string stringTotal = std::to_string(this->total);//convert to string
	return "\x9C" + stringTotal.substr(0, (stringTotal.size() - 4));//remove trailing 0's
}
void Order::calculateTotal()
{
	//reset total and savings to 0 in case a total has already been calculated
	total = 0;
	savings = 0;
	int i = 0;//iterator
	//toggle the second item free in a 2-4-1 discount
	bool discount = false; //when true, one 2-4-1 has been parsed

	for (i; i < items.size(); i++)//for item in the order vector
	{
		if (items[i]->getType() == "Appetiser")//if the item is an appetiser
		{
			//convert item pointer to appetiser pointer to access twoForOne bool
			Appetiser* app = dynamic_cast<Appetiser*>(items[i]);

			//assign class field to a bool variable
			bool twoForOne = app->getTwoForOne();

			//if the appetiser is a two for one and the first of 2
			if ((twoForOne == true) && (discount == false))
			{
				discount = true;//show one 2-4-1 is found
				total += (app->getPrice());//add item to total
			}
			//if the appetiser is a two for one and 2 of 2
			else if ((twoForOne == true) && (discount == true))
			{
				savings += (app->getPrice());//add to savings and don't count it in total
				discount = false; //dont charge but change discount bool to false
			}
			else
				total += (app->getPrice());//if appetiser not in 2-4-1, just add regular price

		}
		else //add to total
			total += (items[i]->getPrice());//add item to total
	}
}

std::string Order::toString()
{
	std::string orderWords;//string holding all order info
	int i = 0;//iterator
	std::string orderNum; //numbers order items
	orderWords += "----------------Checkout----------------\n";
	
	
	for (i; i < items.size(); i++)//while within the order list
	{
		orderNum = "(" + std::to_string(i + 1) + ") "; //add order number
		orderWords += (orderNum + (items[i]->toString()));//add item to total
		orderWords += "\n";
	}
	orderWords += "----------------------------------------\n";

	//display savings if any
	if (this->getSavings() > 0)
	{
		orderWords += "2-4-1 discount applied! Savings: " + (this->getSavingsString()) + "\n"; 
	}
	//display total
	orderWords += "Total: " + (this->getTotalString()) + "\n"; 
	return orderWords;
}

void Order::printReceipt()
{
	std::string receiptText = this->toString(); //get receipt text
	std::ofstream receipt("receipt.txt"); //open streamwriter
	if (receipt.is_open())
	{
		receipt << receiptText;
		receipt.close();//write text in and close
	}
}