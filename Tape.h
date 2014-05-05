#ifndef TAPE_H
#define TAPE_H
#include "Direction.h"
#include <string>
#include <fstream>

using namespace std;

class Tape
{
private:
    string cells;
    int current_cell;
    char blank;

public:
    Tape();
    void Load(ifstream & definition, bool & valid);
    void View() const;
    void Initialize(string input_string);
    void Update(char write_character, direction move_direction);
    string Left(int maximum_number_of_cells) const;
    string Right(int maximum_number_of_cells) const;
    char Get_Current_Character() const;
    char Get_Blank_Character() const;
    bool Is_First_Cell() const;

};

#endif
