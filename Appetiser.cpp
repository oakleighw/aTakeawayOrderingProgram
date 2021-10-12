#include "Appetiser.h"
//Constructor to set Appetiser fields
Appetiser::Appetiser(std::string _name, float _price, int _calories, bool _shareable, bool _twoForOne)
{
	this->name = _name;
	this->price = _price;
	this->calories = _calories;	
	this->shareable = _shareable;
	this->twoForOne = _twoForOne;
}

bool Appetiser::getSharable()
{
	return shareable;
}
bool Appetiser::getTwoForOne()
{
	return twoForOne;
}

//These two methods will be used to aid menu display
std::string Appetiser::getTwoForOneString()
{
	if (twoForOne == true)
	{
		return "(2-4-1)";
	}
	else
		return "";//return empty string if false
}
std::string Appetiser::getSharableString()
{
	if (shareable == true)
	{
		return "(shareable)";
	}
	else
		return "";//return empty string if false

}

std::string Appetiser::getType() const
{
	return classType;
}

std::string Appetiser::toString()
{
	return (getName() + ": " + "\x9C" + getStringPrice() + ", " + getStringCalories() + " cal" + " " + getTwoForOneString() + getSharableString());
}

std::ostream &operator<<(std::ostream &output, Appetiser &A) 
{
	output << A.getName() << ": " << "\x9C" << A.getStringPrice() << ", "<< A.getStringCalories() << " cal" <<" "<< A.getTwoForOneString() << A.getSharableString();
	return output;
}