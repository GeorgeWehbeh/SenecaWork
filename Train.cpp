
#define _CRT_SECURE_NO_WARNINGS
/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.h
// Version 1.0
// Date	2020/01/29
// Author George Wehbeh
// Description
// Tests Train module, adds functionality of new functions in order
//to allow for cargo to be a class, and to allow for increasing and
//decreasing of cargo weight and swapping of cargo between trains.
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include "Train.h"
using namespace std;
namespace sdds {
	void Train::setTrain(const char* str, int number) {
		char nullByte[3]{ '\0'};
		if (str == nullptr || strcmp(str, "") == 0 || number < 1) {
			strcpy(name, nullByte);
			number = 0;
		}
		else {
			strcpy(name,str);
			id = number;
		}
		cargo = nullptr;
	}
	bool Train::isEmpty() const{
		bool TrueF = true;
		if (name == nullptr || strcmp(name, "") == 0 || id < 1 ) {
			TrueF = true;
		}
		else {
			TrueF = false;
		}
		return TrueF;
	}
	void Train::display() const{
		cout << "***Train Summary***" << endl;
		if (isEmpty()) {
			cout << "This is an empty train." << endl;
		}
		else {
			cout << "Name: " << name << "ID: " << id << endl;

			if (cargo) {
				cout << "Cargo: " << cargo->pullDescription() << " Weight: " << setprecision(2)<< fixed << cargo->pullWeight() << endl;
			}
			else {
				cout << "No cargo on this train." << endl;
			}
		}
	}

	void Train::loadCargo(Cargo load) {
			cargo = new Cargo[1];
			cargo->init(load.pullDescription(), load.pullWeight());
		}
	void Train::unloadCargo() {
		delete[] cargo;
		cargo = nullptr;
	}
	char* Cargo::pullDescription() {
		return description;
	}
	double Cargo::pullWeight() {
		return weight;
	}
	void Cargo::init(const char* Descrip, double Weight) {
		if (strlen(Descrip)> MAX_DESC) {
			string cutString(Descrip, MAX_DESC-1);
			int n = cutString.length();
			char* array;
			array = new char[n+1];
			strcpy(array, cutString.c_str());
			strcpy(description, array);
		}
		else {
			strcpy(description , Descrip);
		}
		if (Weight < MIN_WEIGHT || Weight > MAX_WEIGHT) {
			weight = MIN_WEIGHT;
		} 
		else {
			weight = Weight;
		}
	}

	bool Train::swapCargo(Train& swap) {
		bool TrueF = false;
		if (cargo) {
			PlaceHolder = cargo;
			cargo = swap.cargo;
			swap.cargo = PlaceHolder;
			TrueF = true;
		}
		else {
			TrueF = false;
		}
		return TrueF;
	}
	bool Train::increaseCargo(double Increase) {
		bool TrueF = false;
		if (cargo) {
			if (cargo->pullWeight() == MAX_WEIGHT ) {
				TrueF = false;
			}
			else if (Increase > MAX_WEIGHT || cargo->pullWeight() + Increase > MAX_WEIGHT) {
				cargo->init(cargo->pullDescription(), MAX_WEIGHT);
				TrueF = true;
			}
			else {
				cargo->init(cargo->pullDescription(), cargo->pullWeight()+Increase);
				TrueF = true;
			}
		}
		else {
			TrueF = false;
		}
		return TrueF;
	}
	bool Train::decreaseCargo(double Decrease) {
		bool TrueF = false;
		if (cargo) {
			if (cargo->pullWeight() - Decrease < MIN_WEIGHT) {
				TrueF = false;
			}
			else {
				cargo->init(cargo->pullDescription(), cargo->pullWeight()-Decrease);
				TrueF = true;
			}
		}
		else {
			TrueF = false;
		}
		return TrueF;
	}


}