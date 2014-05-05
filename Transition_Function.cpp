#include "Transition_Function.h"
#include "Transition.h"
#include "Direction.h"
#include "stringplay.h"
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

void Transition_Function::Load(ifstream & definition,bool & valid)
{
    string line;
    int pos = definition.tellg();
    getline(definition, line);
    if(trim(line, " \t").empty())
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
        pos = definition.tellg();
        getline(definition,line);

        stringstream parseme(line);
        string current;
        parseme >> current;
        if(current.compare("INITIAL_STATE:")==0)
        {
            break;
        }
        string source_state;
        string read_character;
        string destination_state;
        string write_character;
        direction move_direction;
        try{
            source_state = current;
            parseme >> read_character;
            parseme >> destination_state;
            parseme >> write_character;
            parseme >> move_direction;
            Transition tran(source_state, read_character[0], destination_state, write_character[0], move_direction);
            transitions.push_back(tran);
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
        cout << "\u03B4(" << transitions[i].Source_State() << ", " << transitions[i].Read_Character() << ") = (";
        cout << transitions[i].Destination_State() << ", " << transitions[i].Write_Character() << ", " << transitions[i].Move_Direction() << ")\n";
    }
    cout << "\n";
}
int Transition_Function::Size() const
{
	return transitions.size();
}

string Transition_Function::Source_State(int index) const
{
	return transitions[index].Source_State();
}

char Transition_Function::Read_Character(int index) const
{
	return transitions[index].Read_Character();
}

string Transition_Function::Destination_state(int index) const
{
	return transitions[index].Destination_State();
}

char Transition_Function::Write_Character(int index) const
{
	return transitions[index].Write_Character();
}

bool Transition_Function::Is_Defined_Transition(string source_state, char read_character, string & destination_state, char & write_character, direction & move_direction) const
{
    for (int index = 0; index<transitions.size();index++)
    {
        if ((transitions[index].Source_State() == source_state) &&
            (transitions[index].Read_Character() == read_character))
        {
            destination_state = transitions[index].Destination_State();
            write_character=transitions[index].Write_Character();
            move_direction = transitions[index].Move_Direction();
            return true;
    	}
    }
    return false;
}

bool Transition_Function::Is_Source_State(string state) const
{
    for (int index =0; index<transitions.size();index++)
    {
        if (transitions[index].Source_State() == state)
        {
            return true;
        }
    }
	return false;
}
