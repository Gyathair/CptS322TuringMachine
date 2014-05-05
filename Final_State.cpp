#include "Final_State.h"
#include "String_Pointer.h"
#include <string>
using namespace std;

int Final_State::number_of_states = 0;

Final_State::Final_State()
{
	name = new string;
	++number_of_states;
}

Final_State::Final_State(string state_name)
{
	name = new string(state_name);
	++number_of_states;
}

Final_State::Final_State(const Final_State & state)
{
	name = new string(*state.name);
	++number_of_states;
}

Final_State::~Final_State()
{
	delete name;
	--number_of_states;
}

Final_State & Final_State::operator=(const Final_State& state)
{
	if(this != &state)
	{
		*name = *state.name;
	}
	return *this;
}

void Final_State::Get_Name(string & state_name) const
{
	state_name = *name;
}

void Final_State::Set_Name(string state_name)
{
	*name = state_name;
}

int Final_State::Total_Number_Of_States()
{
	return number_of_states;
}
