
#include "Rectangle.hpp"
#include "Point.hpp"
#include <Utils/Utils.hpp>
#include <limits>
#include <sstream>
#include <Utils/Logger.hpp>
#include <cmath>

#include <Bridges/RectangleAreaBridge.hpp>
#include <Bridges/RectanglePerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys;

CRectangle::CRectangle(const BridgesModel& inBridges)
    : CShape(inBridges), width_(ZERO), height_(ZERO)
{
    if (!isPossibleToCreate(width_, height_))
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
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::CRectangle(double width, double height, const BridgesModel& inBridges)
    : CShape(inBridges), width_(width), height_(height)
{
    if (!isPossibleToCreate(width_, height_))
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
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::CRectangle(const CRectangle& inVal)
    : CShape(inVal), width_(inVal.width_), height_(inVal.height_)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_COPY_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::~CRectangle()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

double CRectangle::calculateArea()
{
    double retVal = boost::any_cast<double>(
    bridgesMap_.fetch(bridgeModelKeys::rectangle::AREA).perform(
    { 
        { dataBusKeys::rectangle::SIDE_FST, width_ },
        { dataBusKeys::rectangle::SIDE_SND, height_ }
    }));
    return retVal;
}

double CRectangle::calculatePerimeter()
{
    double retVal = boost::any_cast<double>(
        bridgesMap_.fetch(bridgeModelKeys::rectangle::PERIMETER).perform(
    {
        { dataBusKeys::rectangle::SIDE_FST, width_ },
        { dataBusKeys::rectangle::SIDE_SND, height_ }
    }));
    return retVal;
}

CRectangle* CRectangle::buildNewObj(double width, double height)
{
    return new CRectangle(width, height);
}

CRectangle* CRectangle::buildNewObj(CRectangle* inObj)
{
    return new CRectangle(*inObj);
}

CRectangle* CRectangle::buildNewObj(const BridgesModel& inBridges)
{
    return new CRectangle(inBridges);
}

bool CRectangle::isPossibleToCreate(double inWidth, double inHeight)
{
    return inWidth > 0 && inHeight > 0;
}

bool CRectangle::isPossibleToCreate()
{
    return isPossibleToCreate(width_, height_);
}

std::string CRectangle::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << RECTANGLE << BRACKET_OPEN
        << WIDTH << SEPARATOR
        << width_
        << COMMA_SPACE
        << HEIGHT << SEPARATOR
        << height_
        << BRACKET_CLOSE;

    return retVal.str();
}

