#pragma once

#include <vector>
#include <string>

#include <Handlers/IShapeHandler.hpp>

class CGoHandler : public IShapeHandler

{
public:
    CGoHandler(std::vector<std::string>& inCommand);
    virtual ~CGoHandler();
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;

protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};