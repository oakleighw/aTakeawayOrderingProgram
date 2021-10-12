#pragma once
#include <string>
#include <vector>
#include "ItemList.h"
class Menu :
    public ItemList
{
public: 
    //constructor that initialises path to menu.csv
    Menu(std::string _menuPath);

    //menu destructor that removes item pointers
    ~Menu();

    //Displays Menu in an attractive way, ordered by Item type
    std::string toString() override;

    //converts "y" or "n" strings to bools
    bool toBool(std::string _answer);

    //access menu items
    std::vector<Item*> getMenuItems();
    
    //returns error if item out of bounds of menu vector
    void checkMenu(int _menuNumber);

private:

    //stores path of menu
    std::string menuPath;

    //loads from CSV File into a/m/b categories
    //used within constructor
    void loadFromCSV();

    //converts row of csv file to menu item and pushes to item vector
    //loadFromCsv() helper function
    void itemToMenu(std::vector<std::string> _row);

};

