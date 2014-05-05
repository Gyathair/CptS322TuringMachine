#include "States.h"
#include "State.h"
#include "Crash.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void States::Load(ifstream &definition, bool &valid)
{
	string line;
	int pos = definition.tellg();
	getLine(definition, line);
	if(trim(line).empty())
		getline(definition, line);
	stringstream parseme(line);
	string current;
	parseme >> current;
	if(convertToUpper(current).compare("STATES:")!=0)
	{
		definition.seekg(pos, definition.beg);
		cout << "States not defined\n";
		valid = false;
		return;
	}

	while(parseme >> current)
	{
		State st(current);
		states.add(st);
	}
}

void States::View() const
{
	cout << "Q = { ";
	cout << Element(1);
	for(int i = 1; i < states.size(); i ++)
	{
		cout << ", " << Element(i);
	}
	cout << "}\n\n";
}

int States::Size() const
{
	return State::Total_Number_Of_States();
}

string States::Element(int index) const
{
	if(index >= states.size())
		throw Crash("States' index outside of bounds");
	string name;
	states[index].Get_Name(name);
	return name;
}

bool States::Is_Element(string state) const
{
	for(int i = 0; i < states.size(); i ++)
	{
		string name;
		states[i].Get_Name(&name);
		if(name.compare( state ) == 0 )
			return true;
	}
	return false;
}
