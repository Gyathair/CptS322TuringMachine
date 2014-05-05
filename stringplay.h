#ifndef STRINGPLAY_H
#define STRINGPLAY_H


#include <iostream>
#include <string>
#include <cstddef>
#include <stdio.h>
#include <ctype.h>


std::string trim(const std::string& str,
                 const std::string& whitespace);

std::string convertToUpper(std::string &buffer);

std::string convertToLower(std::string &buffer);
std::string keepAlphaNumericWhitespace(std::string &buffer);

#endif
