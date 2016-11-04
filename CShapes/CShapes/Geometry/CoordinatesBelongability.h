#pragma once

#include <map>

class CCoordinatesBelongability
{
private:
    std::map<char, bool> belongability;
public:
    CCoordinatesBelongability(std::map<char, bool> inVals);
    ~CCoordinatesBelongability();

    operator bool();
};

