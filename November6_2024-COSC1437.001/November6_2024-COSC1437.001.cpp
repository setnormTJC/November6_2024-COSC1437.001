// November6_2024-COSC1437.001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string> 
#include <vector>

using std::cout; 
using std::string; 


class AirFilterType
{
	int length, width, height; 
	double price; 

	//we are getting at "operator overloading" here with this example
public:
	AirFilterType(int length, int width, int height, double price)
		:length(length), width(width), height(height), price(price)
	{

	}
};

int main()
{
	AirFilterType expensiveAirFilter{ 20, 25, 1, 8.99 };
	AirFilterType cheapAirFilter	{ 20, 25, 1, 2.99 };
	AirFilterType smallerAirFilter	{ 16, 20, 1, 3.99 }; 
	AirFilterType largerAirFilter	{ 25, 25, 1, 4.99 }; 

	std::vector<AirFilterType> stackOfFilters =
	{
		expensiveAirFilter,
		cheapAirFilter,
		smallerAirFilter,
		largerAirFilter
	};

	//can we SORT the stack of air filters? 

	//can we PRINT an AirFilterType?


	//string someWord = "alpha"; 
	//cout << someWord.find('a') << "\n"; //hangman 
	//cout << someWord.find('a', 1) << "\n";
}

