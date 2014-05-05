#include "Transition.h"
#include "Direction.h"
#include <string>

using namespace std;

Transition::Transition( string source_state, char read_character, string destination_state, char write_character, direction move_direction):
    source(source_state),
    read(read_character),
    destination(destination_state),
    write(write_character),
    move(move_direction)
{
}

string Transition::Source_State() const
{
    return source;
}

char Transition::Read_Character() const
{
    return read;
}

string Transition::Destination_State() const
{
    return destination;
}

char Transition::Write_Character() const
{
    return write;
}

direction Transition::Move_Direction() const
{
    return move;
}
