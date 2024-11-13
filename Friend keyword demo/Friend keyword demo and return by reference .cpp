// Friend keyword demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout; 
using std::string; 

class Person
{
private: 
	string phoneNumber = "867-5309";

public: 
	//friend function: 
	friend void demoFriendFunction(Person friendPerson);
	
	//friend class 
	friend class FriendOfPerson;
};


//friend 

void demoFriendFunction(Person friendPerson)
{
	cout << "I am calling you, bro, at your number, which is: " << friendPerson.phoneNumber << "\n";
	//oops!
}


const std::string& getProgramName()
{
	static const std::string programName{ "Calculator" }; // now a non-static local variable, destroyed when function ends

	return programName;
}

//friends have access to private members of a class 0

int main()
{
	//Person somePerson; 

	cout << getProgramName() << "\n";
}
