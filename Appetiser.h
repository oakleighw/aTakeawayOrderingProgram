#pragma once
#include "Item.h"
#include <iostream>
class Appetiser :
    public Item
{
public:
    //initialises an appetiser
    Appetiser(std::string _name, float _price, int _calories, bool _shareable, bool _twoForOne);

    //get name of class
    std::string getType() const override;

    //returns string summary of an Appetiser
    std::string toString() override;

    //toString() equivalent which uses '<<' operator to display summary of the appetiser
    friend std::ostream &operator<<(std::ostream &output, Appetiser &A);

    //returns sharable in string format
    std::string getSharableString();

    //access sharable bool
    bool getSharable();

    //returns 2-4-1 in string format
    std::string getTwoForOneString();

    //access 2-4-1 bool
    bool getTwoForOne();

private:
    bool shareable;
    bool twoForOne;
    const std::string classType = "Appetiser";
};

