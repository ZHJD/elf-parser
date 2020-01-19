#include <sstream>
#include <iomanip>
#include <string>
#include "utility.h"


template <typename T>
std::string int_to_hex(T integer)
{
    std::stringstream stream;
    stream << "0x"
           << std::setfill('0')
           << std::setw(sizeof(T) * 2)
           << std::hex
           << integer;
    return stream.str();
}


