/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.h
// Version 1.0
// Date	2020/01/29
// Author George Wehbeh
// Description
// Tests Train module
//Upgraded from in lab to include new function prototypes for TrainTester2.cpp
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_TRAIN_H__
#define SDDS_TRAIN_H__
namespace sdds {
	const int MAX_NAME = 31;
	const int MAX_DESC = 21;
	const double MAX_WEIGHT = 700.555;
	const double MIN_WEIGHT = 40.444;
	class Cargo {
		char description[MAX_DESC];
		double weight;
	public:
		void init(const char* Descrip, double Weight);
		char* pullDescription();
		double pullWeight();
	};
	class Train {
		char name[MAX_NAME];
		int id;
		Cargo* cargo;
		Cargo* PlaceHolder;
	public:
		void setTrain(const char* str, int number);	
		void unloadCargo();
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo load);
		bool swapCargo(Train& swap);
		bool increaseCargo(double Increase);
		bool decreaseCargo(double Decrease);
	};


}
#endif // !SDDS_TRAIN_H__
