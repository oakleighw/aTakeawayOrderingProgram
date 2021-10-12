#pragma once
#include "Item.h"
#include <iostream>
class Beverage :
    public Item
{
public:
    Beverage(std::string _name, float _price, int _calories, int _volume, float _abv);

    //gets name of class
    std::string getType() const override;

    //returns string summary of a Beverage
    std::string toString() override;

    //toString() equivalent which uses '<<' operator to display summary of the Beverage
    friend std::ostream &operator<<(std::ostream &output, Beverage &B);

    //access abv
    float getAbv();

    //returns abv in string format
    std::string getStringAbv();

    //returns true if beverage is alcoholic
    bool isAlcoholic();

    //access volume
    int getVolume();

private:
    const std::string classType = "Beverage";
    int volume;
    float abv;
};

