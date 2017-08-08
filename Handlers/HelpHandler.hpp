#pragma once

#include <vector>
#include <string>
#include <Utils/Utils.hpp>
#include <Handlers/IShapeHandler.hpp>

class CHelpHandler final : public IShapeHandler
{
public:
    CHelpHandler(std::vector<std::string>& inCommand);
    virtual ~CHelpHandler();
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
