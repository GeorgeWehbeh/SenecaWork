/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory & Function Overloading
// File Gift.cpp
// Version 1.0
// Date 2020/01/26
// Author George Wehbeh
//ID: 104884192
// Description
// In this module we have all of our important functions for handling gifts,
// the most important of which (pretaining to this DIY) being wrap, unwrap
//and the now fourth gifting function. Wrap allowing us to wrap an unwrapped
//gift, selecting how many layers of wrap we want and then allowing user 
//input for the pattern that they would like on each wrap, unwrap allowing
//us to remove all wraps from a wrapped gift, and the new gifting function 
//allowing us to prepare a new gift by calling all of our other gifting 
//functions.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Gift.h"
using namespace std;
namespace sdds {
	void gifting(char* g_description){
		cout << "Enter gift description: ";
		cin.width(MAX_DESC);
		cin >> g_description;
	}
	void gifting(double& g_price){
		int err;
		do{
			err = 0;
			cout << "Enter gift price: ";
			cin >> g_price;
			if (g_price < 0 || g_price > MAX_PRICE) {
				cout << "Gift price must be between 0 and" << MAX_PRICE << endl;
				err = 1;
			}
		} while (err == 1);
	}
	void gifting(int& g_units){
		int err1;
		do {
			err1 = 0;
			cout << "Enter gift units: ";
			cin >> g_units;
			if (g_units < 1) {
				cout << "Gift units must be at least 1" << endl;
				err1 = 1;
			}
		} while (err1 == 1);
	}
	void display(const Gift& gifting){
		cout << "Gift Details:" << endl;
		cout << "Description: " << gifting.g_description << endl;
		cout << "Price: "<< gifting.g_price << endl;
		cout << "Units: " << gifting.g_units << endl;
		if (gifting.wrap_layers ==0) {
			cout << "Unwrapped" << endl;
		}
		else{
			cout << "Wrap Layers: " << gifting.wrap_layers << endl;
			for (int i = 0; i < gifting.wrap_layers;i++) {
				cout << "Wrap #" << i+1 << ": " << gifting.wrap[i].pattern << endl;
			}
		}
	}
	bool wrap(Gift& wrapping) {
		bool TrueFalse = 0;
		char Uinput[MAX_PATTERN];
		int size = 0;

		if (wrapping.wrap_layers > 0) {
			cout << "Gift is already wrapped!" << endl;
			TrueFalse = 0;
		}
		else if (wrapping.wrap_layers == 0) {
			cout << "Wrapping gifts..." << endl;
			int err;
			do {
				err = 0;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> wrapping.wrap_layers;
				if (wrapping.wrap_layers < 1) {
					cout << "Layers at minimum must be 1, try again." << endl;
					err = 1;
				}
			} while (err ==1);

			wrapping.wrap = new Wrapping[wrapping.wrap_layers];
			
			for (int i = 0; i < wrapping.wrap_layers; i++) {
				cout << "Enter wrapping pattern #" << i + 1 <<": ";
				cin >> Uinput;
				size = strlen(Uinput)+1;
				wrapping.wrap[i].pattern = new char[size];
				strcpy(wrapping.wrap[i].pattern, Uinput);
			}
			TrueFalse = 1;
		}
		return TrueFalse;
	}
	bool unwrap(Gift& wrapping) {
		bool TrueFalse = 0;
		//struct Gift c;
		if (wrapping.wrap_layers == 0) {
			cout << "Gift isn't wrapped! Can't unwrap." << endl;
			TrueFalse = 0;
		}
		else if (wrapping.wrap_layers > 0) {
			cout << "Gift being unwrapped." << endl;
			delete[] wrapping.wrap;
			wrapping.wrap = nullptr;
			wrapping.wrap_layers = 0 ;
			TrueFalse = 1;
		}
		return TrueFalse;
	}
	void gifting(Gift& newGift) {
		cout << "Preparing a gift..." << endl;
		gifting(newGift.g_description);
		cin.ignore(2000, '\n'); // clear input buffer
		gifting(newGift.g_price);
		cin.ignore(2000, '\n'); // clear input buffer
		gifting(newGift.g_units);
		cin.ignore(2000, '\n');
		wrap(newGift);
		cout << endl;
	}

}