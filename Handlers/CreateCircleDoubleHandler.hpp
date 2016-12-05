#pragma once

#include <vector>
#include <string>

#include <Handlers/IShapeHandler.hpp>

class CCreateCircleDoubleHandler : public IShapeHandler
{
public:
    CCreateCircleDoubleHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateCircleDoubleHandler() {};
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};