#include "State.h"
#include "String_Pointer.h"
#include <string>
using namespace std;

int State::number_of_states = 0;

State::State()
{
	name = new string;
	++number_of_states;
}

State::State(string state_name)
{
	name = new string(state_name);
	++number_of_states;
}

State::State(const State & state)
{
	name = new string(*state.name);
	++number_of_states;
}

State::~State()
{
	delete name;
	--number_of_states;
}

State & State::operator=(const State& state)
{
	if(this != &state)
	{
		*name = *state.name;
	}
	return *this;
}

void State::Get_Name(string & state_name) const
{
	state_name = *name;
}

void State::Set_Name(string state_name)
{
	*name = state_name;
}

int State::Total_Number_Of_States()
{
	return number_of_states;
}
