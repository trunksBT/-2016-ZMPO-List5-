#pragma once

#include <vector>
#include <string>
#include <Utils/Utils.hpp>
#include "IHandler.hpp"

class CPoint;
class IShapeHandler : public virtual IHandler
{
public:
    IShapeHandler(std::vector<std::string>& inCommand);
    virtual ~IShapeHandler();
    virtual CODE purePerform(CShapeWithSize inCache) = 0;
    virtual CODE checkArgsAndPerform(CShapeWithSize inCache) = 0;
    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
};

