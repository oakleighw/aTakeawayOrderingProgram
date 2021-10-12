#include "Beverage.h"
//constructor which initialises beverage fields
Beverage::Beverage(std::string _name, float _price, int _calories, int _volume, float _abv)
{
	this->name = _name;
	this->price = _price;
	this->calories = _calories;
	this->volume = _volume;
	this->abv = _abv;
}

std::string Beverage::getType() const
{
	return classType;
}

//if alcohol volume > 0, beverage is alcoholic
bool Beverage::isAlcoholic()
{
	return (abv > 0) ? true : false;
}

int Beverage::getVolume()
{
	return volume;
}

float Beverage::getAbv()
{
	return abv;
}
std::string Beverage::getStringAbv()
{
	if (abv != 0)
	{//convert to string and remove float trailing 0's
		std::string stringAbv = std::to_string(this->abv);
		return (stringAbv.substr(0, (stringAbv.size() - 4))) + "%";
	}
	else
		return "";//returns empty string if abv is 0
}

std::string Beverage::toString()
{
	//if alcoholic, display abv %
	if (isAlcoholic())
		return (getName() + ": " + "\x9C" + getStringPrice() + ", " + getStringCalories() + " cal" + " " + "(" + std::to_string(getVolume()) + "ml, " + getStringAbv() + ")");
	else
		return (getName() + ": " + "\x9C" + getStringPrice() + ", " + getStringCalories() + " cal" + " " + "(" + std::to_string(getVolume()) + "ml)");
}
std::ostream &operator<<(std::ostream &output, Beverage &B) 
{
	if (B.isAlcoholic())
	{
		output << B.getName() << ": " << "\x9C" << B.getStringPrice() << ", " << B.getStringCalories() << " cal" << " " << "(" << std::to_string(B.getVolume()) << "ml, " << B.getStringAbv() << ")";
		return output;
	}
	else
	{
		output << B.getName() << ": " << "\x9C" << B.getStringPrice() << ", " << B.getStringCalories() << " cal" << " " << "(" << std::to_string(B.getVolume()) << "ml)";
		return output;
	}
}