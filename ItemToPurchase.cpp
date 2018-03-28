#include "ItemToPurchase.h"
#include<iomanip>

//Global Variables
int DOLLARS_AND_CENTS = 2; 

ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity) {
	itemName = name;
	itemDescription = description;
	itemPrice = price;
	itemQuantity = quantity; 
}

string ItemToPurchase::GetName() {
	return itemName; 
}

double ItemToPurchase::GetPrice() {
	return itemPrice; 
}

int ItemToPurchase::GetQuantity() {
	return itemQuantity; 
}

void ItemToPurchase::SetName(string itemName) {
	this->itemName = itemName; 
}

void ItemToPurchase::SetPrice(double itemPrice) {
	this->itemPrice = itemPrice; 
}

void ItemToPurchase::SetQuantity(int itemQuantity) {
	this->itemQuantity = itemQuantity; 
}

void ItemToPurchase::SetDescription(string description) {
	itemDescription = description;
}

string ItemToPurchase::GetDescription() {
	return itemDescription;
}

void ItemToPurchase::PrintCost() {
	double subTotal = itemQuantity * itemPrice; 
	cout << itemName << " " << itemQuantity;
	cout << fixed << setprecision(DOLLARS_AND_CENTS) << " @ $" << itemPrice << " = $" << subTotal << endl;
}

void ItemToPurchase::PrintDescription() {
	cout << itemName << ": " << itemDescription << "." << endl; 
}


