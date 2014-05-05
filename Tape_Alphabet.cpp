#include "Tape_Alphabet.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void Tape_Alphabet::Load(ifstream &definition, bool &valid)
{
	string line;
	int pos = definition.tellg();
	getLine(definition, line);
	if(trim(line).empty())
		getline(definition, line);
	stringstream parseme(line);
	string current;
	parseme >> current;
	if(convertToUpper(current).compare("TAPE_ALPHABET:")!=0)
	{
		definition.seekg(pos, definition.beg);
		cout << "Tape Alphabet not defined\n";
		valid = false;
		return;
	}

	while(parseme >> current)
	{
		alphabet.add(current[0]);
	}
}

void Tape_Alphabet::View() const
{
	cout << "\u0393 = { ";
	cout << alphabet[0];
	for(int i = 1; i < alphabet.size(); i++)
	{
		cout << ", " << alphabet[i];
	}
	cout << " }\n\n";
}

int Tape_Alphabet::Size() const
{
	return alphabet.size();
}

char Tape_Alphabet::Element(const int& index) const
{
	return alphabet[index];
}

bool Tape_Alphabet::Is_Element(const char& value) const
{
	return false;
}
