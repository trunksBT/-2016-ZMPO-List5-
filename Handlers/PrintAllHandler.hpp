#pragma once

#include <vector>
#include <string>

#include <Handlers/IShapeHandler.hpp>

class CPrintAllHandler final : public IShapeHandler
{
public:
    CPrintAllHandler(std::vector<std::string>& inCommand);
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
