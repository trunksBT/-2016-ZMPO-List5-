#pragma once

#include <map>

class CCoordinatesBelongability
{
private:
    std::map<char, bool> belongability;

public:
    CCoordinatesBelongability();
    CCoordinatesBelongability(std::map<char, bool> inVals);

public:
    operator bool();
    bool& operator[](char inKey);
};

