// ShoppingListCreator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class itemType { 
public:
	struct aisleStruct { //Items will be seperated by aisle using this struct
		int typeNum;
		string typeName;
	};

	aisleStruct aisle;

	vector<itemType> itemAisle;

	void createAisle(vector<itemType> &x) { //Creates vector that contains Aisle options
		vector<string> aisleNames = { "Fruits and Veggies", "Deli", "Bakery", "Seafood", "Dry Goods", "Dairy", "Frozen" };
		itemType y;
		for (int i = 0; i < aisleNames.size(); i++)
		{
			y.aisle.typeNum = i + 1;
			y.aisle.typeName = aisleNames[i];
			itemAisle.push_back(y);
		}
	}
} type;

class groceries {

	struct itemStruct { //Parameters items contain
		string name;
		string quantity;
		itemType aisleNumber;
	};

	itemStruct item;

public:
	vector<groceries> list; //Vector Groceries stored in

	void printList(vector<groceries> &x, vector<itemType> &y) { //Print list of items and quantity
		cout << "-------------------------" << endl;
		cout << "(Item's sorted by Aisle)" << endl << endl;
		for (int i = 0; i < y.size(); i++){ //sorts items by aisle in store
			int aislePrinted = 0;
			for (int o = 0; o < x.size(); o++) {
				if (y[i].aisle.typeNum == x[o].item.aisleNumber.aisle.typeNum){
					aislePrinted++;
					if (aislePrinted == 1){ //Aisle will print once on top of items belonging to that aisle
						cout << "(" << "Aisle " << i + 1 << ")" << x[o].item.aisleNumber.aisle.typeName << ":" << endl;
					}
					cout << x[o].item.quantity << " " << x[o].item.name << endl;
				}
			}
		}
	}

	void addItem(vector<groceries> &x, vector<itemType> &y) { //add item to list
		groceries z;
		string name;
		string quantity;
		itemType type; //User's selection in itemType data type
		int typeNum; //Take number from user's selection

		cout << "Enter name for new entry: ";
		getline(cin, name);
		cout << "How many?(Text Acceped): ";
		getline(cin, quantity);
		cout << endl;
		for (int i = 0; i < y.size(); i++) { //Prints item type choices
			cout << y[i].aisle.typeNum << " " << y[i].aisle.typeName << endl;
		}
		cout << "Please select number of aisle item belongs to: ";
		cin >> typeNum;
		type = y[typeNum - 1];

		z.item.name = name;
		z.item.quantity = quantity;
		z.item.aisleNumber = type;
		x.push_back(z);
	}

	void deleteItem(vector<groceries> &x) { //Remove item from list
		int y;
		for (int i = 0; i < x.size(); i++) {
			cout << (i + 1) << ": " << x[i].item.quantity << " " << x[i].item.name << endl;
		}
		cout << endl << "Type item number you would like to delete: ";
		cin >> y;
		x.erase(x.begin() + (y-1));
	}
} groc;

void mainMenu() { //Menu that shows on program start up
	cout << "-------------------------" << endl;
	cout << "Options: " << endl;
	cout << "1 adds items" << endl;
	cout << "2 deletes items" << endl;
	cout << "3 prints items" << endl;
	cout << endl;
	cout << "Enter number for option you wish to select:  ";
}

int main() {
	cout << "ShoppingListCreator!" << endl;
	char again = 'y';
	int choice;
	type.createAisle(type.itemAisle);

	while (again == 'y') {
		mainMenu();
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (choice != 1 && choice != 2 && choice != 3) { //Trap choices outside of options
			cout << "Please choose options 1 to 3: ";
			cin >> choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (choice == 1) {
			groc.addItem(groc.list, type.itemAisle);
		}
		else if (choice == 2) {
			groc.deleteItem(groc.list);
		}
		else if (choice == 3) {
			groc.printList(groc.list,type.itemAisle);
		}
		cout << "-------------------------" << endl;
		cout << "Would you like to continue?(y/n): ";
		cin >> again;
		while (again != 'y' && again != 'Y' && again != 'n' && again != 'N') { //Traps choices outside of options
			cout << "Please enter y for Yes or n for No: ";
			cin >> again;
		}
	}
	return 0;
}

