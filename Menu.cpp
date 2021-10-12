#include "Menu.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"
#include <fstream>
#include <sstream>
#include <iostream>

//constructor that initialises path to menu.csv and loads csv
Menu::Menu(std::string _menuPath) {
	this -> menuPath = _menuPath;
	loadFromCSV();
}

//check if choice selected is within menu
void Menu::checkMenu(int _menuNumber)
{
	if (_menuNumber >= this->items.size() || _menuNumber < 0)
	{
		std::cout << "An Item was not found" << std::endl;
		throw 404; //throw error if item not found
	}
}

//menu destructor
Menu::~Menu()
{
	for (auto item : this->items)
	{
		delete item;//delete every item pointer.
	}
	items.clear();
}

std::vector<Item*> Menu::getMenuItems()
{
	return this->items;
}

bool Menu::toBool(std::string _answer) 
{
	return (_answer == "y") ? true : false;//converts string to bool
}

//converts row of csv file to menu item and pushes to item vector
void Menu::itemToMenu(std::vector<std::string> _row)
{
	//instantiate based on field contents
	if (_row[0] == "a")
	{
		//initialise new Appetiser object to a pointer & add to items array
		Appetiser* app = new Appetiser(_row[1], std::stof(_row[2]), std::stoi(_row[3]), toBool(_row[4]), toBool(_row[5]));
		items.push_back(app);
	}
	else if (_row[0] == "m")
	{
		//initialise new MainCourse object to a pointer & add to items array
		MainCourse* mainC = new MainCourse(_row[1], std::stof(_row[2]), std::stoi(_row[3]));
		items.push_back(mainC);
	}
	else if (_row[0] == "b")
	{
		//initialise new Beverage object to a pointer & add to items array
		Beverage* bev = new Beverage(_row[1], std::stof(_row[2]), std::stoi(_row[3]), std::stoi(_row[6]), std::stof(_row[7]));
		items.push_back(bev);
	}
}

//loads from CSV File into a/m/b categories
void Menu::loadFromCSV() {

	//read csv file
	std::ifstream myFile(menuPath);
	
	std::string row;//row of csv

	std::vector<std::string> rowBuffer;//temporarily holds row contents
	
	std::string field;//csv field
	
	if (myFile.is_open())
	{
		//read each csv row
		while (getline(myFile, row))
		{
			
			std::stringstream rowStream(row);

			//read each field within row
			while (getline(rowStream, field, ','))
			{
				//add each field to vector
				rowBuffer.push_back(field);
			}

			//determine item based on row contents and add to items vector
			itemToMenu(rowBuffer);
			
			//clear vector buffer for next line
			rowBuffer.clear();
		}
	}
	//close file
	myFile.close();

}

//Displays Menu in attractive way, ordered by Item type
std::string Menu::toString() 
{
	//string holding entire menu
	std::string menuWords;
	//a style element for ease of reading
	std::string separator = "----------------";
	//Menu subtitles
	std::string appTitle = separator + "Appetisers" + separator;
	std::string mainDishTitle = separator + "Main Dishes" + separator;
	std::string bevTitle = separator + "Beverages" + separator;

	//if subtitle isn't written = 0
	//if subtitle is written = 1
	bool appWritten = 0;
	bool mainWritten = 0;
	bool bevWritten = 0;
	unsigned int i = 0; //iterator
	std::string menuNum; //holds menu number
	
	//while within menu items list
	while (i < items.size())
	{
		menuNum = "(" + std::to_string(i + 1) + ") "; //saves menu item number e.g. (1)...
		//Appetiser section
		if (items[i]->getType() == "Appetiser")
		{
			if (appWritten == 0)//write "Appetisers" title
			{
				menuWords += appTitle + "\n";
				appWritten = 1;
			}
			//creates a line of text containing the item
			menuWords += (menuNum + items[i]->toString() + "\n");
			i++;
		}
		//MainCourse section
		else if (items[i]->getType() == "MainCourse")
		{
			if (mainWritten == 0)//write "Main Dishes" title
			{
				menuWords += mainDishTitle + "\n";
				mainWritten = 1;
			}
			menuWords += ((menuNum + items[i]->toString()) + "\n");
			i++;
		}
		//Beverage section
		else if (items[i]->getType() == "Beverage")
		{
			if (bevWritten == 0)//write "Beverages" title
			{
				menuWords += bevTitle + "\n";
				bevWritten = 1;
			}
			menuWords += ((menuNum + items[i]->toString()) + "\n");
			i++;
		}
		else break;
	}

	return menuWords;

}