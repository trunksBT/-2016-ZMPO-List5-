
#include "Circle.hpp"
#include "Point.hpp"
#include <Utils/Utils.hpp>
#include <limits>
#include <sstream>
#include <Utils/Logger.hpp>
#include <cmath>

#include <Bridges/CircleAreaBridge.hpp>
#include <Bridges/CirclePerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys;

CCircle::CCircle(const BridgesModel& inBridges)
    : CShape(inBridges), radious_(ZERO)
{
    if (!isPossibleToCreate(radious_))
    {
        Logger()
            << ERROR << SEPARATOR
            << THIS_SHAPE_CANNOT_EXIST
            << POST_PRINT;
    }

    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << CIRCLE
            << POST_PRINT;
    }
}

CCircle::CCircle(double inRadious,  const BridgesModel& inBridges)
    : CShape(inBridges), radious_(inRadious)
{
    if (!isPossibleToCreate(radious_))
    {
        Logger()
            << ERROR << SEPARATOR
            << THIS_SHAPE_CANNOT_EXIST
            << POST_PRINT;
    }

    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_ARG1_PRE_PRINT
            << CIRCLE
            << POST_PRINT;
    }
}

CCircle::CCircle(const CCircle& inVal)
    : CShape(inVal), radious_(inVal.radious_)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_COPY_PRE_PRINT
            << CIRCLE
            << POST_PRINT;
    }
}

CCircle::~CCircle()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << CIRCLE
            << POST_PRINT;
    }
}

double CCircle::calculateArea()
{
    double retVal = boost::any_cast<double>(
    bridgesMap_.fetch(circle::AREA).perform(
    { 
        { dataBusKeys::circle::RADIOUS, radious_ }
    }));
    return retVal;
}

double CCircle::calculatePerimeter()
{
    double retVal = boost::any_cast<double>(
        bridgesMap_.fetch(circle::PERIMETER).perform(
    {
        { dataBusKeys::circle::RADIOUS, radious_ }
    }));
    return retVal;
}

CCircle* CCircle::buildNewObj(double inRadious)
{
    return new CCircle(inRadious);
}

CCircle* CCircle::buildNewObj(CCircle* inObj)
{
    return new CCircle(*inObj);
}

CCircle* CCircle::buildNewObj()
{
    return new CCircle();
}

bool CCircle::isPossibleToCreate(double inRadious)
{
    return inRadious > ZERO;
}

bool CCircle::isPossibleToCreate()
{
    return isPossibleToCreate(radious_);
}

std::string CCircle::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << CIRCLE << BRACKET_OPEN
        << RADIOUS << SEPARATOR
        << radious_
        << BRACKET_CLOSE;

    return retVal.str();
}

