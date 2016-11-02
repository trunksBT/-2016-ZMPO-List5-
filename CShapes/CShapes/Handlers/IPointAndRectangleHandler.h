#pragma once

#include <vector>
#include <string>

#include "IPointHandler.h"
#include "IShapeHandler.h"

class IPointAndRectangleHandler : public virtual IPointHandler, public  virtual IShapeHandler
{
public:
    IPointAndRectangleHandler(std::vector<std::string>& inCommand);
    virtual ~IPointAndRectangleHandler();

    virtual CODE purePerform(CShapeWithSize inCache) = 0;
    virtual CODE checkArgsAndPerform(CShapeWithSize inCache) = 0;
    virtual CODE purePerform(CPointWithSize inCache) = 0;
    virtual CODE checkArgsAndPerform(CPointWithSize inCache) = 0;

    virtual CODE purePerform(
        CPointWithSize inPointCache,
        CShapeWithSize inRectangleCache) = 0;
    virtual CODE checkArgsAndPerform(
        CPointWithSize inPointCache,
        CShapeWithSize inRectangleCache) = 0;

    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
};