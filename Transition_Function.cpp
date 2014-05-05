#include "Transition_Function.h"
#include "Transition.h"
#include "Direction.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void Transition_Function::Load(ifstream & definition,bool & valid)
{
	//TODO: this section
}
void Transition_Function::View() const
{
    // \u03B4
    cout << "Transitions:\n";
    for(int i = 0; i < transitions.size(); i++)
    {
        cout << "\u03B4(" << transitions[i].source_state() << ", " << transitions[i].read_character() << ") = (";
        cout << transitions[i].destination_state() << ", " << destinations[i].write_character() << ", " << transitions[i].move_direction() << ")\n";
    }
    cout << "\n";
}
int Transition_Function::Size() const
{
	return transitions.size();
}

string Transition_Function::Source_State(int index) const
{
	return transitions[index].source_state();
}

char Transition_Function::Read_Character(int index) const
{
	return transitions[index].read_character();
}

string Transition_Function::Destination_state(int index) const
{
	return transitions[index].destination_state();
}

char Transition_Function::Write_Character(int index) const
{
	return transitions[index].write_character();
}

bool Transition_Function::Is_Defined_Transition(string source_state, char read_character, string & destination_state, char & write_character, direction & move_direction) const
{
    for (int index =0; index<transitions.size();index++)
    {
        if ((transitions[index].source_state() == source_state) &&
            (transitions[index].read_character() == read_character))
        {
            destination_state = transitions[index].destination_state();
            write_character=transition[index].write_character();
            move_direction = transitions[index].move_direction();
            return true;
    	}
    }
    return false;
}

bool Transition_Function::Is_Source_State(string state) const
{
    for (int index =0; index<transitions.size();index++)
    {
        if (transitions[index].source_state() == state)
        {
            return true;
        }
    }
	return false;
}
