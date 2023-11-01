#include "Numbers.h"

#include<regex>
//#include <algorithm>

bool Numbers::RandomNum(int& num)
{
    std::srand(std::time(NULL));
    num = std::rand();
    return true;
}

bool Numbers::isNumber(std::string str)
{
    auto isNum = [](std::string str)->bool {
        std::regex reg("[+-]*\\d+\\.?(\\d*[Ee]*([+-])?\\d+)?");
        return std::regex_match(str, reg);
    };
    return true;
}

