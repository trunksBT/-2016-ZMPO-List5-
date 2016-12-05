
#include "Triangle.hpp"
#include "Point.hpp"
#include <Utils/Utils.hpp>
#include <limits>
#include <sstream>
#include <Utils/Logger.hpp>
#include <cmath>

#include <Bridges/TriangleAreaBridge.hpp>
#include <Bridges/TrianglePerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys;

CTriangle::CTriangle(const BridgesModel& inBridges)
    : CShape(inBridges), sideFst_(ZERO), sideSnd_(ZERO), sideThrd_(ZERO)
{
    if (!isTriangleProper(sideFst_, sideSnd_, sideThrd_))
    {
        Logger()
            << ERROR << SEPARATOR
            << THIS_TRIANGLE_CANNOT_EXIST
            << POST_PRINT;
    }

    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << TRIANGLE
            << POST_PRINT;
    }
}

CTriangle::CTriangle(double inSideFst, double inSideSnd, double inSideThrd,
    const BridgesModel& inBridges)
    : CShape(inBridges), sideFst_(inSideFst), sideSnd_(inSideSnd), sideThrd_(inSideThrd)
{
    if (!isTriangleProper(sideFst_, sideSnd_, sideThrd_))
    {
        Logger()
            << ERROR << SEPARATOR
            << THIS_TRIANGLE_CANNOT_EXIST
            << POST_PRINT;
    }

    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_ARG1_PRE_PRINT
            << TRIANGLE
            << POST_PRINT;
    }
}

CTriangle::CTriangle(const CTriangle& inVal)
    : CShape(inVal), sideFst_(inVal.sideFst_), sideSnd_(inVal.sideSnd_), sideThrd_(inVal.sideThrd_)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_COPY_PRE_PRINT
            << TRIANGLE
            << POST_PRINT;
    }
}

CTriangle::~CTriangle()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << TRIANGLE
            << POST_PRINT;
    }
}

double CTriangle::calculateArea()
{
    double retVal = boost::any_cast<double>(
    bridgesMap_.fetch(triangle::AREA).perform(
    { 
        { dataBusKeys::triangle::SIDE_FST, sideFst_ },
        { dataBusKeys::triangle::SIDE_SND, sideSnd_ },
        { dataBusKeys::triangle::SIDE_THRD, sideThrd_ }
    }));
    return retVal;
}

double CTriangle::calculatePerimeter()
{
    double retVal = boost::any_cast<double>(
        bridgesMap_.fetch(triangle::PERIMETER).perform(
    {
        { dataBusKeys::triangle::SIDE_FST, sideFst_ },
        { dataBusKeys::triangle::SIDE_SND, sideSnd_ },
        { dataBusKeys::triangle::SIDE_THRD, sideThrd_ }
    }));
    return retVal;
}

CTriangle* CTriangle::buildNewObj(double inSideFst, double inSideSnd, double inSideThrd)
{
    return new CTriangle(inSideFst, inSideSnd, inSideThrd);
}

CTriangle* CTriangle::buildNewObj(CTriangle* inObj)
{
    return new CTriangle(*inObj);
}

CTriangle* CTriangle::buildNewObj()
{
    return new CTriangle();
}

std::string CTriangle::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << TRIANGLE << BRACKET_OPEN
        << SIDE << SEPARATOR
        << sideFst_ << SEPARATOR
        << sideSnd_ << SEPARATOR
        << sideThrd_ << SPACE
        << BRACKET_CLOSE;

    return retVal.str();
}

