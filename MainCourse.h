#pragma once
#include "Item.h"
#include <iostream>
class MainCourse :
    public Item
{
public:
    //MainCourse constructor
    MainCourse(std::string _name, float _price, int _calories);

    std::string getType() const override; //returns classtype

    //toString() equivalent which uses '<<' operator to display summary of the Main Course
    friend std::ostream &operator<<(std::ostream &output, MainCourse &M);

private:
    //gets name of class
    const std::string classType = "MainCourse";
};

