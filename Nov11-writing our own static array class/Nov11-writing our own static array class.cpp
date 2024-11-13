// Nov11-writing our own static array class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector> //a DYNAMIC array (one whose size can SHRINK and grow)

#include<array>//a STATIC array 

#include<cassert> 

//let's write OUR OWN version of <vector> (eventually) -> new operator 
using std::cout; 


template<typename T, int MAX_CAPACITY> 
class CustomStaticArray
{
private: 
	T theListOfThings[MAX_CAPACITY]; //declaration of a static array of Type T

public: 
	CustomStaticArray() = default; //what will this do for integers, chars, floats, booleans, etc? 
	CustomStaticArray(T initialValue)
	{
		for (int i = 0; i < MAX_CAPACITY; ++i)
		{
			theListOfThings[i] = initialValue;
		}
	}

	void print()
	{
		for (int i = 0; i < MAX_CAPACITY; ++i)
		{
			cout << theListOfThings[i] << "\n";
		}
	}

	void insert(int INDEX_AT_WHICH_TO_INSERT, T itemToInsert)
	{
		//if ()
		//{
		//	throw std::exception //we'll talk a bit about this later ...
		//}
		assert(INDEX_AT_WHICH_TO_INSERT < MAX_CAPACITY); //we may not remember what this is doing yet ...

		theListOfThings[INDEX_AT_WHICH_TO_INSERT] = itemToInsert; 
	}

	T& operator [] (int desiredIndex)
	{
		return theListOfThings[desiredIndex];

	}

};


template<typename T1, typename T2> //T as in (data) TYPE -> this is another form of "polymorphism" 
void printSomething(T1 a, T2 b)
{
	//for (int i = 0; i < numberOfTimesToPrint; ++i)
	//{
		cout << "Printing the input: " << a << "\t" << b << "\n";
//	}
}

int main()
{
	//Car carObject; 
	CustomStaticArray<std::string, 3> myCustomStaticArray{ "Bob" };
	myCustomStaticArray.print(); 

	//this will use the DEFAULT constructor!
	CustomStaticArray<int, 6> somePrimes;// = { 1, 3, 5, 7 }; //must use std::initializer_list for this ...
	somePrimes.insert(0, 1); //inserts 1 at index = 0 
	somePrimes.insert(1, 3); 
	somePrimes.insert(2, 5); 
	somePrimes.insert(3, 7);
	somePrimes.insert(4, 11);
	somePrimes[5] = 13; 
	somePrimes.insert(66, 2); 

	//cout << "here!" << somePrimes[5] << "\n";


	cout << "\n\n\n";
	somePrimes.print(); 

	//printSomething("asdfasdf", 1);
	//printSomething(1, 'a');

	//double pi = 3.14; 
	//printSomething(pi, 'z');

	//std::array<
	//std::array<std::string, 6> fourThings = { 1, "Bob", "Carol", "Darth (vader)"}; 
	//can we write OUR own custom static array class? 

	//cout << "How much do you want?\n";
	//int numberOfDesiredElements; 

	//std::cin >> numberOfDesiredElements; 
	//int numsList[5];// = { 1, 2,3 ,4, 5 };

	//int otherListOfNumbers[5]; 

	//numsList + otherListOfNumbers 

	//cout << numsList << "\n";

}
