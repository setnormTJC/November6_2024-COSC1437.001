// Playing with a few C++ data structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<vector> 

#include<map>

using std::cout; 
using std::vector; 
using std::string; 
using std::map; 


struct LatitudeLongitude
{
	double latitude; 
	double longitude; 

	LatitudeLongitude(double latitude, double longitude)
		:latitude(latitude), longitude(longitude)
	{

	}
	
	bool operator < (const LatitudeLongitude other) const
	{
		//latitude = 123; 

		return this->latitude < other.latitude; 
	}


};

int main()
{
	LatitudeLongitude coordinatesOfSomePlaceInCoteDIvoire{ 6.8, -5.2 };


	map<LatitudeLongitude, string> coordinatesToCityNamesMap =
	{
		{{32, -95}, "Tyler (roughly)" },//first place is Tyler 

		{{ 6.8, -5.2 }, "Yamoussoukro"}
	};

	coordinatesToCityNamesMap.insert({ {38, -83}, "Somewhere in Kentucky! Huzzah!" });

	coordinatesToCityNamesMap.insert({ {40.6, -73.97}, "New York, NY" });

	//int i = 0; 
	//while (i < 4)
	//{
	//	cout << "Enter some coordinates (latitude first, then longitude), we'll check and see if that location is in our MAP!\n";
	//	double userLatitude, userLongitude;

	//	std::cin >> userLatitude >> userLongitude;

	//	cout << "That was? found in the map, and the name of the location is: "
	//		<< coordinatesToCityNamesMap[{userLatitude, userLongitude}] << "\n";

	//	++i;

	//}


	vector<string> englishWords =
	{
		"I",
		"have",
		"hunger"
	};

	vector<string> spanishWords =
	{
		"Yo",
		"tengo",
		"hambre"
	}; 


	std::map<string, string> englishToSpanishMap; 


	cout << "Enter a word in English, we'll translate (MAP) it to its equivalent in Spanish:\n";
	string inputWord; 
	std::cin >> inputWord; 

	cout << "The corresponding word to" << inputWord << "in Spanish is ... : \n"; 



	vector<string> frenchWords =
	{
		"Je",
		"ai", //J'ai  
		//"femme", 
		"faim"
	}; 


}
