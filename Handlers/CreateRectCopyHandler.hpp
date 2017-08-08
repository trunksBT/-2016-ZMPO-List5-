#pragma once

#include <vector>
#include <string>
#include <Utils/Utils.hpp>
#include <Handlers/IShapeHandler.hpp>

class CCreateRectCopyHandler final : public IShapeHandler
{
public:
    CCreateRectCopyHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateRectCopyHandler();
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
protected:
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
