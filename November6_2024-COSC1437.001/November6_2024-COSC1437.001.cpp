// November6_2024-COSC1437.001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string> 
#include <vector>

#include<algorithm>

using std::cout; 
using std::string; 


class AirFilterType
{
	int length, width, height; 
	double price; 


public: 
	AirFilterType()
	{

	};


	AirFilterType(int length, int width, int height, double price)
		:length(length), width(width), height(height), price(price)
	{

	};

	void print() const
	{
		//length = 123; 

		cout << "Air filter data: " << length << "x" << width << "x" << height << " inches, Price: $" << price << "\n";
	}

	//we are getting at "operator overloading" here with this example
/*The less than operator will compare two filters by their PRICES*/
	bool operator < (const AirFilterType& otherAirFilter)
	{
		//if (this->price < otherAirFilter.price)
		//{
		//	return true;
		//}

		//else
		//{
		//	return false;
		//}
		 
		//one-line alternative to the if/else above: 
		return (this->price < otherAirFilter.price);
	}

	friend std::ostream& operator<<(std::ostream& os, const AirFilterType& airFilter)
	{
		os << "Air filter data: " << airFilter.length
			<< "x" << airFilter.width << "x" << airFilter.height
			<< " inches, Price: $" << airFilter.price;

		return os;
	}

	bool operator == (const AirFilterType& other)
	{
		return
			(this->height == other.height
			&&
			this->length == other.length
			&&
			this->width == other.width
			&&
			this->price == other.price);

	}

	void demoThis()
	{
		cout << "This is : " << this << "\n"; 
	}
};

int main()
{
	AirFilterType someOtherfilter;
	someOtherfilter.demoThis(); 
	cout << "The ADDRESS OF `someOtherAirFilter` is: " << &someOtherfilter << "\n";


	AirFilterType expensiveAirFilter{ 20, 25, 1, 8.99 };
	AirFilterType cheapAirFilter	{ 20, 25, 1, 8.99 };

	if (expensiveAirFilter == cheapAirFilter)
	{
		cout << "SAME air filter attributes...\n";
	}

	else
	{
		cout << "At least one attribute differs between these two air filters\n";
	}

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
	std::sort(stackOfFilters.begin(), stackOfFilters.end());
	
	for (auto& theCurrentAirFilter : stackOfFilters)
	{
		cout << theCurrentAirFilter << "\n";
		//theCurrentAirFilter.print(); 
	}

	//std::sort(stackOfFilters)
	//can we PRINT an AirFilterType?


	//string someWord = "alpha"; 
	//cout << someWord.find('a') << "\n"; //hangman 
	//cout << someWord.find('a', 1) << "\n";
}

