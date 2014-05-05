#include "Tape.h"
#include "Direction.h"
#include "Crash.h"
#include <exception>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	const int success(0);
	Tape tape;
	tape.Initialize("AABB");
	try{
		tape.Update('B','L');
	}
	catch(Crash &error)
	{
		cout << error.what() << ".\n";
	}
	catch (bad_alloc& error)
	{
		cout << "allocation error!\n";
	}
	catch(...)
	{
		cout << "Something went wrong!\n";
	}
	tape.View();
	return success;
}

