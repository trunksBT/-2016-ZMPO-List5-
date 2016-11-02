#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"
#include "IPointHandler.h"

class CCreatePointHandler final : public IPointHandler
{
public:
    CCreatePointHandler(std::vector<std::string>& inCommand);
    CODE checkArgsAndPerform(CPointWithSize inCache) override;
protected:
    CODE purePerform(CPointWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
