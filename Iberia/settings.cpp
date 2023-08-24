#include <iostream>

#include "settings.hpp"

using namespace std;

std::string Settings::Key()
{
    return _key;
}
std::string Settings::Value()
{
    return _value;
}

void Settings::Key(std::string str)
{
    _key = str;
}
void Settings::Value(std::string str)
{
    _value = str;
}

