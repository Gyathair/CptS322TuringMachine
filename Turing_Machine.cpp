#include "Turing_Machine.h"
#include "Tape.h"
#include "Input_Alphabet.h"
#include "Tape_Alphabet.h"
#include "Transition_Function.h"
#include "States.h"
#include "Final_States.h"
#include <string>
#include <vector>
#include <ifstream>

using namespace std;

Turing_Machine::Turing_Machine(string definition_file_name)
{
	//TODO: call load()'s

	//TODO validate TM
}
void Turing_Machine::View_Definition() const
{
	cout << "Definition of Turing Machine\n";
	states.View();
	input_alphabet.View();
	tape_alphabet.View();
	transition_function.View();
	cout << "q0 = " << initial_state << "\n\n";
	tape.View();
	final_states.View();
}

void Turing_Machine::View_Instantaneous_Desc(int maximum_number_of_cells) const
{
	cout << tape.Left(maximum_number_of_cells) << "[" << current_state << "]" << tape.Right(maximum_number_of_cells) << "\n\n";
}

void Turing_Machine::Initialize(string input_string)
{
	if(used)
	{
		cout << "You must terminate currently running machine to start a new one\n\n";
		return;
	}
	original_input_string = input_string;
	current_state = initial_state;
	tape.Initialize(input_string);
	operating = false;
	used = true;
	accepted = false;
	rejected = false;
}

void Turing_Machine::Perform_Transitions(int maximum_number_of_transitions)
{
	if(final_states.Is_Element(current_state))
	{
		operating = false;
		accepted = true;
		used = false;
		return;
	}

    string destination_state;
    char write_character;
    direction move_direction;
	for(int i = 0; i < maximum_number_of_transitions && operating; i++)
	{
		operating = transition_function.Is_Defined_Transition(current_state, tape.Get_Current_Character(), destination_state, write_character, move_direction);
		if(operating==false)
		{
			rejected = true;
			used = false;
			return;
		}
		number_of_transitions++;
		tape.Update(write_character, move_direction);
		current_state = destination_state;
		if(final_states.Is_Element(current_state))
		{
			operating = false;
			accepted = true;
			used = false;
			return;
		}
	}
}

void Turing_Machine::Terminate_Operation()
{
	operating = false;
	used = false;
	accepted = false;
	rejected = false;
}

string Turing_Machine::Get_Input_String() const
{
	return original_input_string;
}

int Turing_Machine::Get_Total_Number_Of_Transitions() const
{
	return number_of_transitions;
}

bool Turing_Machine::Is_Valid_Definition() const
{
	return valid;
}

bool Turing_Machine::Is_Valid_Input_String(string value) const
{
	for(int i = 0; i < value.size(); i++)
	{
		if(!tape_alphabet.Is_Element(value[i]))
			return false;
	}
	return true;
}

bool Turing_Machine::Is_Used() const
{
	return used;
}

bool Turing_Machine::Is_Operation() const
{
	return operating;
}

bool Turing_Machine::Is_Accepted_Input_String() const
{
	return accepted;
}

bool Turing_Machine::Is_Rejected_Input_String() const
{
	return rejected;
}