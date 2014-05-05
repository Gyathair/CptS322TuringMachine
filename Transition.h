#ifndef TRANSITION_H
#define TRANSITION_H
#include "Direction.h"
#include <string>

using namespace std;

class Transition
{
    private:
        string source;
        char read;
        string destination;
        char write;
        direction move;
    public:
        Transition( string source_state, char read_character, string destination_state, char write_character, direction move_direction);
        string Source_State() const;
        char Read_Character() const;
        string Destination_State() const;
        char Write_Character() const;
        direction Move_Direction() const;
};
#endif
