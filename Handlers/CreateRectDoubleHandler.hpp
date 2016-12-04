#pragma once

#include <vector>
#include <string>

#include <Handlers/IShapeHandler.hpp>

class CCreateRectDoubleHandler : public IShapeHandler
{
public:
    CCreateRectDoubleHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateRectDoubleHandler() {};
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};