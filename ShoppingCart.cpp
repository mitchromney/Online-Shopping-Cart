#include "ShoppingCart.h"

//Global Variables
int DOLLAR_AND_CENTS = 2;
const int EMPTY = 0;


ShoppingCart::ShoppingCart(string name, string date) {
	customerName = name;
	cartDate = date; 
}
void ShoppingCart::AddItem(ItemToPurchase newItem) {
	ItemToPurchase anItem;
	bool itemNotInCart = true; 
	for (int i = 0; i < listOfItems.size(); ++i) {
		anItem = listOfItems.at(i);
		if (anItem.GetName() == newItem.GetName()) {
			cout << "Item is already in Cart. Nothing added." << endl;
			itemNotInCart = false; 
		}
	}
	if (itemNotInCart) {
		this->listOfItems.push_back(newItem);
	}
}

string ShoppingCart::GetCustName() {
	return customerName;
}

string ShoppingCart::GetCartDate() {
	return cartDate;
}

void ShoppingCart::RemoveItem(string itemName) {
	ItemToPurchase item1;
	bool itemInCart = true; 
	for (int i = 0; i < listOfItems.size(); ++i) {
		item1 = listOfItems.at(i);
		if (item1.GetName() == itemName) {
			listOfItems.erase(listOfItems.begin() + i);
			itemInCart = false;
		}
	}
	if (itemInCart) {
		cout << "Item not found in cart. Nothing removed." << endl; 
	}
}

void ShoppingCart::UpdateQuantity(ItemToPurchase anItem, int newQuantity) {
	ItemToPurchase item1;
	bool ItemIsInList = false; 
	for (int i = 0; i < listOfItems.size(); ++i) {
		item1 = listOfItems.at(i);
		if (item1.GetName() == anItem.GetName()) {
			item1.SetQuantity(newQuantity);
			listOfItems.at(i) = item1;
			ItemIsInList = true; 
		}
	}
	if (ItemIsInList == false) {
		cout << "Item not found in cart. Nothing modified." << endl; 
	}
}

int ShoppingCart::GetQuantityOfItems() {
	ItemToPurchase item1;
	int numItems = 0;
	for (int i = 0; i < listOfItems.size(); ++i) {
		item1 = listOfItems.at(i);
		numItems += item1.GetQuantity();
	}
	return numItems;
}

double ShoppingCart::GetTotalCost() {
	double runningTotal = 0.00;
	ItemToPurchase item1;

	for (int i = 0; i < listOfItems.size(); ++i) {
		item1 = listOfItems.at(i);
		runningTotal += (item1.GetPrice() * item1.GetQuantity());
	}
	return runningTotal;
}

void ShoppingCart::PrintQuantityAndCost(ShoppingCart userCart) {
	ItemToPurchase anItem; 
	string name = userCart.GetCustName();
	string date = userCart.GetCartDate();
	int numItems = userCart.GetQuantityOfItems(); 
	double totalCost = userCart.GetTotalCost(); 
	cout << name << "'s Shopping Cart - " << date << endl;
	if (listOfItems.size() == EMPTY) {
		cout << "Shopping cart is empty." << endl; 
	}
	else {
		cout << "Number of Items: " << numItems << endl << endl;
		for (int i = 0; i < listOfItems.size(); ++i) {
			anItem = listOfItems.at(i);
			anItem.PrintCost();
		}
		cout << endl;
		cout << "Total: $" << fixed << setprecision(DOLLAR_AND_CENTS) << totalCost << endl;
	}
}

void ShoppingCart::PrintAllDescriptions(ShoppingCart userCart) {
	ItemToPurchase anItem;
	string name = userCart.GetCustName();
	string date = userCart.GetCartDate();
	string itemDescription;

	cout << name << "'s Shopping Cart - " << date << endl;
	if (listOfItems.size() == EMPTY) {
		cout << "Shopping cart is empty." << endl;
	}
	else {
		cout << "Item Descriptions" << endl;
		for (int i = 0; i < listOfItems.size(); ++i) {
			anItem = listOfItems.at(i);
			cout << anItem.GetName() << ": " << anItem.GetDescription() << endl;
		}
	}
}