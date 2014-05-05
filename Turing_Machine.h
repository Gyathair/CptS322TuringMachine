#ifndef TURING_MACHINE_H
#define TURING_MACHIN_H
#include "Tape.h"
#include "Input_Alphabet.h"
#include "Tape_Alphabet.h"
#include "Transition_Function.h"
#include "States.h"
#include "Final_States.h"
#include <string>
#include <vector>
using namespace std;
class Turing_Machine
{
private:
	Tape tape;
	Input_Alphabet input_alphabet;
	Tape_Alphabet tape_alphabet;
	Transition_Function transition_function;
	States states;
	Final_States final_states;
	vector<string> description;
	string initial_state;
	string current_state;
	string original_input_string;
	int number_of_transitions;
	bool valid;
	bool used;
	bool operating;
	bool accepted;
	bool rejected;

public:
	Turing_Machine(string definition_file_name);
	void View_Definition() const;
	void View_Instantaneous_Desc(int maximum_number_of_cells) const;
	bool Initialize(string input_string);
	void Perform_Transitions(int maximum_number_of_transitions);
	void Terminate_Operation();
	string Get_Input_String() const;
	int Get_Total_Number_Of_Transitions() const;
	bool Is_Valid_Definition() const;
	bool Is_Valid_Input_String(string value) const;
	bool Is_Used() const;
	bool Is_Operation() const;
	bool Is_Accepted_Input_String() const;
	bool Is_Rejected_Input_String() const;
};
#endif
