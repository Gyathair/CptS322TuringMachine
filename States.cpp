#include "States.h"
#include "State.h"
#include "Crash.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "stringplay.h"

using namespace std;

void States::Load(ifstream &definition, bool &valid)
{
	string line;
	int pos = definition.tellg();
	getline(definition, line);
	if(trim(line, " \t").empty())
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
		states.push_back(st);
	}
}

void States::View() const
{
	cout << "Q = { ";
	cout << Element(0);
	for(int i = 1; i < Size(); i ++)
	{
		cout << ", " << Element(i);
	}
	cout << "}\n\n";
}

int States::Size() const
{
	return states.size();
}

string States::Element(int index) const
{
	if(index >= Size())
		throw Crash("States' index outside of bounds");
	string name;
	states[index].Get_Name(name);
	return name;
}

bool States::Is_Element(string state) const
{
	for(int i = 0; i < Size(); i ++)
	{
		string name;
		states[i].Get_Name(name);
		if(name.compare( state ) == 0 )
			return true;
	}
	return false;
}
