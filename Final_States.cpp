#include "Final_States.h"
#include "Final_State.h"
#include "Crash.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "stringplay.h"
using namespace std;

void Final_States::Load(ifstream &definition, bool &valid)
{
	string line;
	int pos = definition.tellg();
	getline(definition, line);
	if(trim(line, " \t").empty())
		getline(definition, line);
	stringstream parseme(line);
	string current;
	parseme >> current;
	if(convertToUpper(current).compare("FINAL_STATES:")!=0)
	{
		definition.seekg(pos, definition.beg);
		cout << "Final States not defined\n";
		valid = false;
		return;
	}

	while(parseme >> current)
	{
		Final_State final(current);
		final_states.push_back(final);
	}
}

void Final_States::View() const
{
	cout << "F = { ";
	cout << Element(0);
	for(int i = 1; i < Size(); i ++)
	{
		cout << ", " << Element(i);
	}
	cout << "}\n\n";
}

int Final_States::Size() const
{
	return final_states.size();
}

string Final_States::Element(int index) const
{
	if(index >= Size())
		throw Crash("States' index outside of bounds");
	string name;
	final_states[index].Get_Name(name);
	return name;
}

bool Final_States::Is_Element(string state) const
{
	for(int i = 0; i < Size(); i ++)
	{
		string name;
		final_states[i].Get_Name(name);
		if(name.compare( state ) == 0 )
			return true;
	}
	return false;
}
