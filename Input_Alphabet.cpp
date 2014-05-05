#include "Input_Alphabet.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void Input_Alphabet::Load(ifstream &definition, bool &valid)
{
	//TODO
}

void Input_Alphabet::View() const
{
	cout << "\u03A3 = { ";
	cout << alphabet[0];
	for(int i = 1; i < alphabet.size(); i++)
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
	return false;
}
