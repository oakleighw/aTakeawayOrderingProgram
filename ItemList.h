#pragma once
#include <string>
#include <vector>
#include "item.h"

class ItemList //abstract class
{
protected:
	
	std::vector<Item*> items;

	//abstract toString function
	virtual std::string toString() = 0;
public:
	//virtual destructor
	virtual ~ItemList() {};
};

