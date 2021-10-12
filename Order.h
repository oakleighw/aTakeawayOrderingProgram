#pragma once
#include "ItemList.h"
class Order :
    public ItemList
{
private:

    float total = 0;//total bill
    float savings = 0;//money saved from 2-4-1 offers

public:

    //order destructor
    ~Order();

    //add item to order
    void add(Item* _item);

    //remove item from order
    void remove(int _position);

    //returns error if item out of bounds of order vector
    void checkOrder(int _orderNumber);

    //reassess total to pay
    void calculateTotal();

    //get total as a string
    std::string getTotalString();

    //access savings as float;
    float getSavings();
    //access savings as string
    std::string getSavingsString();

    //get order items
    std::vector<Item*> getOrderItems();
    
    //create a text format 
    std::string toString() override;

    //export to text file
    void printReceipt();
};

