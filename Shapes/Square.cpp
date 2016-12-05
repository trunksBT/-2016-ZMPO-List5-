
#include "Square.hpp"
#include "Point.hpp"
#include <Utils/Utils.hpp>
#include <limits>
#include <sstream>
#include <Utils/Logger.hpp>
#include <cmath>

#include <Bridges/SquareAreaBridge.hpp>
#include <Bridges/SquarePerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys;

CSquare::CSquare(const BridgesModel& inBridges)
    : CShape(inBridges), side_(ZERO)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << SQUARE
            << POST_PRINT;
    }
}

CSquare::CSquare(double inSide,  const BridgesModel& inBridges)
    : CShape(inBridges), side_(inSide)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_ARG1_PRE_PRINT
            << SQUARE
            << POST_PRINT;
    }
}

CSquare::CSquare(const CSquare& inVal)
    : CShape(inVal), side_(inVal.side_)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_COPY_PRE_PRINT
            << SQUARE
            << POST_PRINT;
    }
}

CSquare::~CSquare()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << SQUARE
            << POST_PRINT;
    }
}

double CSquare::calculateArea()
{
    double retVal = boost::any_cast<double>(
    bridgesMap_.fetch(square::AREA).perform(
    { 
        { dataBusKeys::square::SIDE, side_ }
    }));
    return retVal;
}

double CSquare::calculatePerimeter()
{
    double retVal = boost::any_cast<double>(
        bridgesMap_.fetch(square::PERIMETER).perform(
    {
        { dataBusKeys::square::SIDE, side_ }
    }));
    return retVal;
}

CSquare* CSquare::buildNewObj(double inSide)
{
    return new CSquare(inSide);
}

CSquare* CSquare::buildNewObj(CSquare* inObj)
{
    return new CSquare(*inObj);
}

CSquare* CSquare::buildNewObj()
{
    return new CSquare();
}

std::string CSquare::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << SQUARE << BRACKET_OPEN
        << SIDE << SEPARATOR
        << side_
        << BRACKET_CLOSE;

    return retVal.str();
}

