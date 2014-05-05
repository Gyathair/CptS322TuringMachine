#include "Turing_Machine.h"
#include "Visible.h"
#include <exception>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

char getKeyInput()
{
	char str[1024];
	cin.getline(str,1024);
	if(str[0]=='\0')
	{
		return '-';
	}
	if(str[1]!='\0')
	{
		return '\0';
	}
	return str[0];
}

int main(int argc, char * argv[])
{
	const int success(0);
	try
	{
	if(argc != 2)
	{
		cout << "Usage: " << argv[0] << " tm\n where tm is the prefix to tm.def and tm.str\n";
		return success;
	}

	int transitionsPerRun = 1;
	bool helpEnabled = false;
	int maxCharacters = 32;

	string misunderstoodCommand = "Sorry, did not understand that command.\nTo enable help, type \'h\'\n";
	string helpCommand = "Command list:<list Commands below>\nDelete\neXit\nHelp\nInsert\nList\nQuit\nRun\nsEt\nshoW\nTruncate\nView\n";
	
	vector<string> listOfInputStrings;
	string definitionFile(argv[1]);
	string inputFile(argv[1]);
	definitionFile.append(".def");
	inputFile.append(".str");

	Turing_Machine tm(definitionFile);
	if(!tm.Is_Valid_Definition())
	{
		return success;
	}

	ifstream inputstringfile(inputFile.c_str());
	if(inputstringfile.good())
	{
		string line;
		int linenum = 1;
		while(inputstringfile.good())
		{
			getline(inputstringfile,line);
			if(tm.Is_Valid_Input_String(line))
				listOfInputStrings.push_back(line);
			else
				cout << "input file: ignored bad line # " << linenum << "\n";
			linenum++;
		}
		inputstringfile.close();
	}

	char command;
	bool changesMadeToStringFile = false;
	do
	{
		cout << "COMMAND: ";
		command = getKeyInput();
		int index=0;
		int newTransitions=0;
		int newTrunk=0;
		bool tminitsuccess=true;
		string inputString;
		switch(command)
		{
			case 'd':
				if(helpEnabled)
					cout << "Enter an index to delete from the list of strings. must be a valid index ( 1 - " << listOfInputStrings.size() << " )\n";
				cout << "Delete index : ";
				index=0;
				cin >> index;
				if(index < 1 || index > listOfInputStrings.size())
				{
					cout << "invalid index\n";
				}
				else
				{
					index--;
					listOfInputStrings.erase(listOfInputStrings.begin()+index);
					changesMadeToStringFile=true;
				}
				break;
			case 'x':
				break;
			case 'h':
				helpEnabled = !helpEnabled;
				if(helpEnabled)
					cout << "Help enabled.\n"<<helpCommand;
				else
					cout << "Help disabled.\n";
				break;
			case 'i':
				if(helpEnabled)
					cout << "Enter a string containing any number of characters from the input alphabet\n";
				cout << "Enter string: ";
				inputString="";
				getline(cin,inputString);
				if(tm.Is_Valid_Input_String(inputString))
				{
					changesMadeToStringFile = true;
					listOfInputStrings.push_back(inputString);
					cout << "String inserted at position " << listOfInputStrings.size() < "\n";
				}else{
					cout << "The string you entered is not in the input alphabet\n";
				}
				break;
			case 'l':
				if(helpEnabled)
					cout << "Displays the list of input strings currently loaded.\n";
				for(int i = 0; i < listOfInputStrings.size();i++)
				{
					cout << (i+1) << ": " << Visible(listOfInputStrings[i]);
				}
				break;
			case 'q':
				if(helpEnabled)
					cout << "Terminating currently processing machine\n";
				tm.Terminate_Operation();
				cout << "Quiting Turing machine processing. " << ((tm.Is_Accepted_Input_String())?"String has been accepted ":((tm.Is_Rejected_Input_String())?"String has been rejected ":"String has neither been accepted or rejected"));
				cout << "in " << tm.Get_Total_Number_Of_Transitions() << " transitions.\n";
				break;
			case 'r':
				if(helpEnabled)
					cout << "Runs the turing machine after selection of an input string\n";
				if(!tm.Is_Used())
				{
					if(listOfInputStrings.size()==0)
					{
						cout << "Please populate the input string list first\n";

					}else{
						if(helpEnabled)
							cout << "Select an input string from the list.\n";
						cout << "Select input string: ";
						cin >> index;
						if(index <1 || index > listOfInputStrings.size())
							cout << "invalid index\n";
						else
							tminitsuccess = tm.Initialize(listOfInputStrings[index-1]);
					}
				}
				if(tm.Is_Used() && tminitsuccess)
				{
					if(tm.Get_Total_Number_Of_Transitions()==0)
					{
						cout << tm.Get_Total_Number_Of_Transitions() << ". ";
						tm.View_Instantaneous_Desc(maxCharacters);
					}
					tm.Perform_Transitions(transitionsPerRun);
					cout << tm.Get_Total_Number_Of_Transitions() << ". ";
					tm.View_Instantaneous_Desc(maxCharacters);
					if(!tm.Is_Operation())
					{
						if(tm.Is_Accepted_Input_String())
							cout << "Accepted string " << tm.Get_Input_String() << " in " << tm. Get_Total_Number_Of_Transitions() << " transitions\n";
						else
							cout << "Rejected string " << tm.Get_Input_String() << " in " << tm. Get_Total_Number_Of_Transitions() << " transitions\n";
					}
				}
				break;
			case 'e':
				if(helpEnabled)
					cout << "Set the number of transitions to do at a time.\n";
				cout << "Number of transitions (" << transitionsPerRun << "): ";
				cin >> newTransitions;
				if(newTransitions < 1)
					cout << "Number of transitions must be positive.\n";
				else
					transitionsPerRun = newTransitions;
				break;
			case 'w':
				if(helpEnabled)
					cout << "Outputs program information\n";
				cout << "CptS322\tSpring 2014\n\n";
				cout << "Instructor: Dr. Corrigan\nAuthor: Daniel Hanlen\n\n";
				cout << "Help is " << ((helpEnabled)?"on":"off") << "\n";
				cout << "String truncated at " << maxCharacters << " characters\n";
				cout << transitionsPerRun << " Transition per run\n";
				cout << "Version: 1.0\n\n";
				cout << "TM: " << argv[1] << "\tTM is currently running on \"" << tm.Get_Input_String() << "\" with " << tm.Get_Total_Number_Of_Transitions() << " transitions\n";
				break;
			case 't':
				if(helpEnabled)
					cout << "Sets how many characters are allowed to the left and right of the current position.\n";
				cout << "Character display limit (" << maxCharacters << "): ";
				cin >> newTrunk;
				if(newTrunk < 1)
					cout << "Display limit must be a positive integer.\n";
				else
					maxCharacters = newTrunk;
				break;
			case 'v':
				if(helpEnabled)
					cout << "Displays the formal definition of the Turing Machine\n";
				tm.View_Definition();
				break;
			case '-':
				break;
			default:
				cout << misunderstoodCommand;
				break;
		}
		cout <<"\n";
	}while(command != 'x');

	cout << "Exiting program. ";

	if(changesMadeToStringFile)
	{
		ofstream outputInputsFileStream(inputFile.c_str());
		if(listOfInputStrings.size()>0)
			outputInputsFileStream << listOfInputStrings[0];
		for(int i = 1; i < listOfInputStrings.size(); i++)
		{
			outputInputsFileStream << "\n" << listOfInputStrings[i];
		}
		cout << "The list of strings has been written to " << inputFile;
	}
	cout << "\n";
	}catch(exception e)
	{
		cout << "Exception: " << e.what();
	}
	return success;
}

