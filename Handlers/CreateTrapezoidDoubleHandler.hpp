#pragma once

#include <vector>
#include <string>

#include <Handlers/IShapeHandler.hpp>

class CCreateTrapezoidDoubleHandler : public IShapeHandler
{
public:
    CCreateTrapezoidDoubleHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateTrapezoidDoubleHandler() {};
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};