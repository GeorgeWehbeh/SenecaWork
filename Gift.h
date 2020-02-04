/***********************************************************************
// OOP244 Workshop 2: DIY
// File Gift.h
// Version 1.0
// Date 2020/01/26
// Author George Wehbeh
//ID: 104884192
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#pragma once
#ifndef SDDS_GIFT_H__
#define SDDS_GIFT_H__
namespace sdds {
	const int MAX_DESC = 16;
	const double MAX_PRICE = 999.99;
	const int MAX_PATTERN = 25;
	struct Wrapping {
		char* pattern;
	};
	struct Gift {
		char g_description[MAX_DESC];
		double g_price;
		int g_units;
		Wrapping *wrap;
		int wrap_layers;
	};

	
	void gifting(char* g_description);
	void gifting(double& g_price);
	void gifting(int& g_units);
	void display(const Gift& giftng);
	bool wrap(Gift& wrapping);
	bool unwrap(Gift& wrapping);
	void gifting(Gift& newGift);
}
#endif // !SDDS_GIFT_H__
