#ifndef STATES
#define STATES

#include "State.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class States
{
	public:
		void Load(ifstream &definition, bool &valid);
		void View() const;
		int Size() const;
		string Element(int index) const;
		bool Is_Element(string state) const;
	private:
		vector<State> states;
};

#endif