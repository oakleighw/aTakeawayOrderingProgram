#pragma once
#include <string>
class Item
{
public:
	//access name
	std::string getName();

	//access price
	float getPrice();
	//return price as a string, removing trailing float 0's
	std::string getStringPrice();

	//access calories
	int getCalories();
	//return calories as string
	std::string getStringCalories();

	//will get class name(e.g. Appetiser/Main course/Beverage)
	virtual std::string getType() const; 

	//returns string summary of an item
	virtual std::string toString();
protected:
	std::string name;	
	float price = 0;
	int calories = 0;
};

