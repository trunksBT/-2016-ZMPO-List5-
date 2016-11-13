
#include "CoordinatesBelongability.hpp"
#include <Utils/Utils.hpp>

using namespace geometry;

CCoordinatesBelongability::CCoordinatesBelongability()
{
    belongability = { { X, false }, { Y, false } };
}

CCoordinatesBelongability::CCoordinatesBelongability(std::map<char, bool> inVals)
{
    belongability = inVals;
}

CCoordinatesBelongability::operator bool()
{
    return belongability[X] && belongability[Y];
}

bool& CCoordinatesBelongability::operator[](char inKey)
{
    return belongability[inKey];
}
