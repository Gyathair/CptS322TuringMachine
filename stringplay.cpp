#include "stringplay.h"

#include <iostream>
#include <string>
#include <cstddef>
#include <stdio.h>
#include <ctype.h>


std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
    const std::size_t strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const std::size_t strEnd = str.find_last_not_of(whitespace);
    const std::size_t strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::string convertToUpper(std::string &buffer)
{
    for(unsigned int l=0; l<buffer.length(); l++)
    {
        buffer[l]=toupper(buffer[l]);
    }
    return buffer;
}

std::string convertToLower(std::string &buffer)
{
    for(unsigned int l=0; l<buffer.length(); l++)
    {
        buffer[l]=tolower(buffer[l]);
    }
    return buffer;
}
std::string keepAlphaNumericWhitespace(std::string &buffer)
{
    std::string temp = buffer;
    for(unsigned int l=0; l<temp.length(); l++)
    {
        if(isalnum(temp[l]) || isspace(temp[l]))
        {
            buffer[l]=temp[l];
        }
    }
    return buffer;
}
