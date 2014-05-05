#include "Tape_Alphabet.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void Tape_Alphabet::Load(ifstream &definition, bool &valid)
{
	//TODO
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
