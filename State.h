#ifndef STATE_H
#define STATE_H

#include "String_Pointer.h"
#include <string>

using namespace std;

class State
{
private:
	String_Pointer name;
	static int number_of_states;

public:
	State();
	State(string state_name);
	State(const State & state);
	virtual ~State();

	State & operator=(const State & state);

	void Get_Name(string & state_name) const;
	void Set_Name(string state_name);

	static int Total_Number_Of_States();
};

typedef State * State_Pointer;

#endif

