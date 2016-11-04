#include "stdafx.h"
#include "CoordinatesBelongability.h"
#include "../Utils.hpp"

using namespace geometry;

CCoordinatesBelongability::CCoordinatesBelongability(std::map<char, bool> inVals)
{
    belongability = inVals;
}

CCoordinatesBelongability::~CCoordinatesBelongability()
{}

CCoordinatesBelongability::operator bool()
{
    return belongability[X] && belongability[Y];
}

