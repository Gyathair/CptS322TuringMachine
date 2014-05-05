#include "Transition_Function.h"
#include "Transition.h"
#include "Direction.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void Transition_Function::Load(ifstream & definition,bool & valid)
{
    string line;
    int pos = definition.tellg();
    getLine(definition, line);
    if(trim(line).empty())
        getline(definition, line);

    if(convertToUpper(line).compare("TRANSITION_FUNCTION:")!=0)
    {
        definition.seekg(pos, definition.beg);
        cout << "Transition Function section either not defined or in correct location\n";
        valid = false;
        return;
    }
    while(true)
    {
        getline(definition,line);
        if(line.empty())
            continue;

        pos = definition.tellg();

        stringstream parseme(line);
        string current;
        parseme >> current;
        if(current.compare("INITIAL_STATE:"))
        {
            break;
        }
        string source_state;
        string read_character;
        string destination_state;
        string write_character;
        direction move_direction;
        try{
            parseme >> source_state;
            parseme >> read_character;
            parseme >> destination_state;
            parseme >> write_character;
            parseme >> move_direction;
            Transition tran(source_state, read_character[0], destination_state, write_character[0], move_direction);
            transitions.add(tran);
        }catch(...)
        {
            cout << "malformed transition at line beginning with : " << source_state << "\n";
            valid = false;
        }
    }
    definition.seekg(pos);
}
void Transition_Function::View() const
{
    // \u03B4 = lower case delta
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
