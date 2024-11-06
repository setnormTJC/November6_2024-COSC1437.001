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
	void demoFriendFunction();
	
	//friend class 
	class FriendOfPerson; 
};


int main()
{
	Person somePerson; 


}
