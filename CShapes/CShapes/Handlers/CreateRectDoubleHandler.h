#pragma once

#include <vector>
#include <string>

#include "IPointAndRectangleHandler.h"

class CCreateRectDoubleHandler : public virtual IShapeHandler
{
public:
    CCreateRectDoubleHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateRectDoubleHandler();
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};