#pragma once

#include <vector>
#include <string>

#include "IPointAndRectangleHandler.h"

class CCreateRectDefaultHandler : public virtual IShapeHandler
{
public:
    CCreateRectDefaultHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateRectDefaultHandler();
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};