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
	friend void demoFriendFunction();
	
	//friend class 
	friend class FriendOfPerson;
};

void demoFriendFunction()
{
	cout << "I am calling you, bro, at your number, which is: " << Person::phoneNumber << "\n";
	//oops!
}


//friends have access to private members of a class 0

int main()
{
	Person somePerson; 


}
