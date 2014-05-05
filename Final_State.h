#ifndef FINAL_STATE_H
#define FINAL_STATE_H

#include "String_Pointer.h"
#include <string>

using namespace std;

class Final_State
{
private:
	String_Pointer name;
	static int number_of_states;

public:
	Final_State();
	Final_State(string state_name);
	Final_State(const Final_State & state);
	virtual ~Final_State();

	Final_State & operator=(const Final_State & state);

	void Get_Name(string & state_name) const;
	void Set_Name(string state_name);

	static int Total_Number_Of_States();
};

typedef Final_State * State_Pointer;

#endif

