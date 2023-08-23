#include <iostream>

using namespace std;

class Settings
{
    std::string _key;
    std::string _value;

    public:
        std::string Key();
        std::string Value();
        void Key(std::string str);
        void Value(std::string str);
};