#include <iostream>
#include <string>
#include <cctype>
#pragma once 

using namespace std;

class ItemToPurchase {
public:
	string GetName();
	double GetPrice();
	int GetQuantity();

	ItemToPurchase(string name = "none", string description = "none", double price = 0.0, int quantity = 0);

	void SetName(string itemName);
	void SetPrice(double itemPrice);
	void SetQuantity(int itemQuantity);
	void SetDescription(string description);
	string GetDescription();
	void PrintCost();
	void PrintDescription();

private:
	string itemName;
	double itemPrice;
	int itemQuantity;
	string itemDescription;
}; 
