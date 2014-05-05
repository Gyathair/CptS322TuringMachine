#include "State.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	const int success(0);
	string name;
	State x;
	State y("s2");
	State z = y;
	State_Pointer p = new State(z);

	x=*p;
	p->Set_Name("s3");
	delete p;
	x.Get_Name(name);
	cout << "Name of state x is " << name << ".\n";
	cout << "Total number of states is " << State::Total_Number_Of_States() << ".\n";

	return success;
}

