#include "Crash.h"
#include <stdexcept>
#include <string>

using namespace std;

Crash::Crash(string reason):runtime_error(reason.c_str())
{
}
