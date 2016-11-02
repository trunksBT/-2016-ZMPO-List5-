#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"

class CPoint;
class IHandler
{
public:
    IHandler(std::vector<std::string>& inCommand);
    virtual ~IHandler();
    CODE checkTypeAndAmountOfArgs();
    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
protected:
    std::vector<std::string> wholeCommand_;
};

