#include "Item.h"
//Access Item Fields
std::string Item:: getName()
{
	return this->name;
}

float Item::getPrice()
{
	return this->price;
}
std::string Item::getStringPrice()
{
	std::string stringPrice = std::to_string(this->price); //convert to string
	return (stringPrice.substr(0, (stringPrice.size() - 4))); //remove float trailing zeros
}

int Item::getCalories()
{
	return this->calories;
}
std::string Item::getStringCalories()
{
	return (std::to_string(this->calories));
}

std::string Item::getType() const //virtual : will hold class name(e.g.Appetiser/Main course/Beverage)
{
	return 0;
}

std::string Item::toString()
{
	return (getName() + ": " + "\x9C" + getStringPrice() + ", " + getStringCalories() + " cal");
}

