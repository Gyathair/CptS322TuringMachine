#ifndef FINAL_STATES
#define FINAL_STATES

#include "Final_State.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Final_States
{
	public:
		void Load(ifstream &definition, bool &valid);
		void View() const;
		int Size() const;
		string Element(int index) const;
		bool Is_Element(string state) const;
	private:
		vector<Final_State> final_states;
};

#endif