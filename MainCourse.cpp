#include "MainCourse.h"

//constructor to initialise fields
MainCourse::MainCourse(std::string _name, float _price, int _calories) {
	this->name = _name;
	this->price = _price;
	this->calories = _calories;	
}


std::string MainCourse::getType() const
{
	return classType;
}

//toString() equivalent which uses '<<' operator to display summary of the Main Course
std::ostream &operator<<(std::ostream &output, MainCourse &M)
{
	output << M.getName() << ": " << "\x9C" << M.getStringPrice() << ", " << M.getStringCalories() + " cal";
	return output;
}