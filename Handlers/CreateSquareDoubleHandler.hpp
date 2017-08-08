#pragma once

#include <vector>
#include <string>

#include <Handlers/IShapeHandler.hpp>

class CCreateSquareDoubleHandler : public IShapeHandler
{
public:
    CCreateSquareDoubleHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateSquareDoubleHandler() {};
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};