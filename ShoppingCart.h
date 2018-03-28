#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include<iomanip>
#include "ItemToPurchase.h"

#pragma once

using namespace std;

class ShoppingCart {
public:
	ShoppingCart(string name = "none", string date = "January 1, 2016");
	string GetCustName();
	string GetCartDate();
	void AddItem(ItemToPurchase newItem);			
	void RemoveItem(string itemName);     
	void UpdateQuantity(ItemToPurchase anItem, int newQuantity); 
	int GetQuantityOfItems();
	double GetTotalCost(); 
	void PrintQuantityAndCost(ShoppingCart userCart); 
	void PrintAllDescriptions(ShoppingCart userCart); 
private:
	string customerName;
	string cartDate; 
	vector<ItemToPurchase> listOfItems; 
};