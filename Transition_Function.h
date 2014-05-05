#ifndef TRANSITION_FUNCTION_H
#define TRANSITION_FUNCTION_H
#include "Transition.h"
#include "Direction.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Transition_Function
{
    private:
        vector<Transition> transistions;

    public:
        void Load(ifstream & definition,
                bool & valid);
        void View() const;
        int Size() const;
        string Source_State(int index) const;
        char Read_Character(int index) const;
        string Destination_state(int index) const;
        char Write_Character(int index) const;
        bool Is_Defined_Transition(string source_state,
	char read_character,
	string & destination_state,
	char & write_character,
	direction & move_direction) const;
        bool Is_Source_State(string state) const;
};
#endif
