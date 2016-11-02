#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"
#include "IShapeHandler.h"

class CFieldRectHandler final : public IShapeHandler
{
public:
    CFieldRectHandler(std::vector<std::string>& inCommand);
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
