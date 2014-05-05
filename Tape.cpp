#include "Tape.h"
#include "Direction.h"
#include "stringplay.h"
#include "Crash.h"
#include "Visible.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Tape::Tape():cells(" "),current_cell(0), blank(' ')
{
}

void Tape::Load(ifstream & definition, bool &valid)
{
    string value;
    if((definition >> value) && (value.length()==1) && (value[0]!='\\') && (value[0]!='[') && (value[0]!=']') && (value[0]!='<') && (value[0]!='>') && (value[0]>='!') && (value[0]<='~'))
    {
       	blank = value[0];
    }else{
       	cout << "Illegal blank character.\n";
       	valid = false;
	}
	int pos = definition.tellg();
	if(!(definition >> value))
	{
		cout << "Unexpected end of file\n";
		valid = false;
	}
	if(value.empty())
	{
		pos = definition.tellg();
		if(!(definition >> value))
		{
			cout << "Unexpected end of file\n";
			valid = false;
		}
	}

	if ((!(definition >> value)) && (convertToUpper(value)!="FINAL_STATES:"))
	{
	        cout << "Missing keyword after blank character.\n";
	        valid=false;
	}
	definition.seekg(pos);
}

void Tape::View() const
{
	cout << "B = " << blank << "\n\n";
}

void Tape::Initialize(string input_string)
{
	cells = input_string + blank;
	current_cell = 0;
}

void Tape::Update(char write_character, direction move_direction)
{
	move_direction = toupper(move_direction);
	if(move_direction == 'L' && current_cell==0)
		throw Crash("Left move from first cell");
	if(move_direction == 'R' && current_cell==cells.length()-1)
		cells+=blank;

	cells[current_cell]=write_character;
	if(move_direction == 'L')
		current_cell--;
	else
		current_cell++;
}

string Tape::Left(int maximum_number_of_cells) const
{
	int first_cell = max(0,current_cell - maximum_number_of_cells);
	string value = cells.substr(first_cell, current_cell-first_cell);
	if(value.length()<current_cell)
		value.insert(0,"<");
	return value;
}

string Tape::Right(int maximum_number_of_cells) const
{
	int end_cell = cells.length() - 1;
	while(end_cell >= current_cell && cells[end_cell] == blank)
		--end_cell;
	int last_cell = min(end_cell, current_cell + maximum_number_of_cells - 1);
	string value = cells.substr(current_cell,last_cell - current_cell + 1);

	if(value.length() < end_cell - current_cell + 1)
		value.append(">");
	return value;
}

char Tape::Get_Current_Character() const
{
	return cells[current_cell];
}

char Tape::Get_Blank_Character() const
{
	return blank;
}

bool Tape::Is_First_Cell() const
{
	return 0 == current_cell;
}

