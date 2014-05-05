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
        string source_state() const;
        char read_char() const;
        string destination_state() const;
        char write_char() const;
        direction move_direction() const;
};
#endif
