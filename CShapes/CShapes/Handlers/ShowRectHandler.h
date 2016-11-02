#pragma once

#include <vector>
#include <string>

#include "IPointAndRectangleHandler.h"

class CShowRectHandler final : public virtual IShapeHandler
{
public:
    CShowRectHandler(std::vector<std::string>& inCommand);
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
