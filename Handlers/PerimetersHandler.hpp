#pragma once

#include <vector>
#include <string>
#include <Utils/Utils.hpp>
#include <Handlers/IShapeHandler.hpp>

class CPerimetersHandler final : public IShapeHandler
{
public:
    CPerimetersHandler(std::vector<std::string>& inCommand);
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
