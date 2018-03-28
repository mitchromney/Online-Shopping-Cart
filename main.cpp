#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <sstream>
#include <iomanip> 

void GetLineNoNull(string& inpString) {
	getline(cin, inpString);
	if (inpString == "") {
		getline(cin, inpString);
	}
}

int main() {
	string userName;
	string userDate;
	string menuSelection; 
	string itemName;
	string itemDescription;
	double itemPrice;
	int itemQuantity;
	string itemToRemove;

	cout << "Enter Customer's Name: ";
	GetLineNoNull(userName);
	cout << endl;

	cout << "Enter Today's Date: ";
	GetLineNoNull(userDate);
	cout << endl << endl;
	
	ShoppingCart userCart(userName, userDate);
	
	cout << "Enter option: ";
	cin >> menuSelection;
	cout << endl;
	while (menuSelection != "quit") {
		if (menuSelection == "add") {
			cout << "Enter the item name: ";
			GetLineNoNull(itemName);
			cout << "\n Enter the item description: ";
			GetLineNoNull(itemDescription);
			cout << "\n Enter the item price: ";
			cin >> itemPrice;
			cout << "\n Enter the item quantity: ";
			cin >> itemQuantity;
			ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);
			userCart.AddItem(newItem);
		}
		else if (menuSelection == "remove") {
			cout << "Enter name of the item to remove: ";
			GetLineNoNull(itemToRemove);
			cout << endl;
			userCart.RemoveItem(itemToRemove);
		}
		else if (menuSelection == "change") {
			cout << "Enter the item name: ";
			GetLineNoNull(itemName);
			cout << endl;
			cout << "Enter the new quantity: ";
			cin >> itemQuantity;
			cout << endl;
			userCart.UpdateQuantity(itemName, itemQuantity); 

		}
		else if (menuSelection == "descriptions") {
			
			userCart.PrintAllDescriptions(userCart); 
		}
		else if (menuSelection == "cart") {
			
			userCart.PrintQuantityAndCost(userCart);
		}
		else if ((menuSelection == "options")) {
			cout << endl;
			cout << "MENU" << endl;
			cout << "add - Add item to cart" << endl;
			cout << "remove - Remove item from cart" << endl;
			cout << "change - Change item quantity" << endl;
			cout << "descriptions - Output items' descriptions" << endl;
			cout << "cart - Output shopping cart" << endl;
			cout << "options - Print the options menu" << endl; 
			cout << "quit - Quit" << endl; 
		}
		else if ((menuSelection != "options") && (menuSelection != "add") && (menuSelection != "Remove") && (menuSelection != "change") && (menuSelection != "descriptions") && (menuSelection != "cart")) {
			cout << endl;
			cout << "MENU" << endl;
			cout << "add - Add item to cart" << endl;
			cout << "remove - Remove item from cart" << endl;
			cout << "change - Change item quantity" << endl;
			cout << "descriptions - Output items' descriptions" << endl;
			cout << "cart - Output shopping cart" << endl;
			cout << "options - Print the options menu" << endl;
			cout << "quit - Quit" << endl;
		}
		
		cout << "Enter option: ";
		GetLineNoNull(menuSelection); 
		cout << endl; 
		
	}
	cout << "Goodbye."; 
	return 0;
}
