#pragma once

#include <vector>
#include <string>

#include "IPointAndRectangleHandler.h"

class CGoHandler : public virtual IPointAndRectangleHandler

{
public:
    CGoHandler(std::vector<std::string>& inCommand);
    virtual ~CGoHandler();
    CODE checkArgsAndPerform(CPointWithSize inCache) override;
    CODE checkArgsAndPerform(CShapeWithSize inCache) override;
    CODE checkArgsAndPerform(CPointWithSize inPointCache, CShapeWithSize inRectangleCache) override;
protected:
    CODE purePerform(CPointWithSize inPointCache, CShapeWithSize inRectangleCache) override;
    CODE purePerform(CPointWithSize inCache) override;
    CODE purePerform(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};