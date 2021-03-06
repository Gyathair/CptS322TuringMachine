#include "Input_Alphabet.h"
#include "stringplay.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void Input_Alphabet::Load(ifstream &definition, bool &valid)
{	string line;
	int pos = definition.tellg();
	getline(definition, line);
	if(trim(line, " \t").empty())
		getline(definition, line);
	stringstream parseme(line);
	string current;
	parseme >> current;
	if(convertToUpper(current).compare("INPUT_ALPHABET:")!=0)
	{
		definition.seekg(pos, definition.beg);
		cout << "Input Alphabet not defined\n";
		valid = false;
		return;
	}

	while(parseme >> current)
	{
		alphabet.push_back(current[0]);
	}
}

void Input_Alphabet::View() const
{
	cout << "\u03A3 = { ";
	cout << alphabet[0];
	for(int i = 1; i < Size(); i++)
	{
		cout << ", " << alphabet[i];
	}
	cout << " }\n\n";
}

int Input_Alphabet::Size() const
{
	return alphabet.size();
}

char Input_Alphabet::Element(const int& index) const
{
	return alphabet[index];
}

bool Input_Alphabet::Is_Element(const char& value) const
{
	for(int i = 0; i < Size(); i++)
	{
		if(alphabet[i]==value)
			return true;
	}
	return false;
}
