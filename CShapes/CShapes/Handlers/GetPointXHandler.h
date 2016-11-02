#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"
#include "IPointHandler.h"

class CGetPointXHandler final : public IPointHandler
{
public:
    CGetPointXHandler(std::vector<std::string>& inCommand);
    CODE checkArgsAndPerform(CPointWithSize inCache) override;
protected:
    CODE purePerform(CPointWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
