#pragma once

#include <vector>
#include <string>

#include <Handlers/IShapeHandler.hpp>

class CCreateTriangleDoubleHandler : public IShapeHandler
{
public:
    CCreateTriangleDoubleHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateTriangleDoubleHandler() {};
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};