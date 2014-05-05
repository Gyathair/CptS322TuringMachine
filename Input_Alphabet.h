#ifndef input_alphabet_h
#define input_alphabet_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Input_Alphabet
{
	private:
		vector<char> alphabet;
	public:
		void Load(ifstream &definition, bool &valid);
		void View() const;
		int Size() const;
		char Element(const int& index) const;
		bool Is_Element(const char& value) const;
};

#endif
