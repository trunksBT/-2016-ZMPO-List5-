
#include "Trapezoid.hpp"
#include "Point.hpp"
#include <Utils/Utils.hpp>
#include <limits>
#include <sstream>
#include <Utils/Logger.hpp>
#include <cmath>

#include <Bridges/TrapezoidAreaBridge.hpp>
#include <Bridges/TrapezoidPerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys;

CTrapezoid::CTrapezoid(const BridgesModel& inBridges)
    : CShape(inBridges), sideFst_(ZERO), sideSnd_(ZERO),
      legFst_(ZERO), legSnd_(ZERO), height_(ZERO)
{
    //if (!isTrapezoidProper(sideFst_, sideSnd_, sideThrd_))
    //{
    //    Logger()
    //        << ERROR << SEPARATOR
    //        << THIS_TRAPEZOID_CANNOT_EXIST
    //        << POST_PRINT;
    //}

    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << TRAPEZOID
            << POST_PRINT;
    }
}

CTrapezoid::CTrapezoid(double inSideFst, double inSideSnd,
    double inLegFst, double inLegSnd, double inHeight, const BridgesModel& inBridges)
    : CShape(inBridges), sideFst_(inSideFst), sideSnd_(inSideSnd), 
      legFst_(inLegFst), legSnd_(inLegSnd), height_(inHeight)
{
    //if (!isTrapezoidProper(sideFst_, sideSnd_, sideThrd_))
    //{
    //    Logger()
    //        << ERROR << SEPARATOR
    //        << THIS_TRAPEZOID_CANNOT_EXIST
    //        << POST_PRINT;
    //}

    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_ARG1_PRE_PRINT
            << TRAPEZOID
            << POST_PRINT;
    }
}

CTrapezoid::CTrapezoid(const CTrapezoid& inVal)
    : CShape(inVal), sideFst_(inVal.sideFst_), sideSnd_(inVal.sideSnd_),
    legFst_(inVal.legFst_), legSnd_(inVal.legSnd_), height_(inVal.height_)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_COPY_PRE_PRINT
            << TRAPEZOID
            << POST_PRINT;
    }
}

CTrapezoid::~CTrapezoid()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << TRAPEZOID
            << POST_PRINT;
    }
}

double CTrapezoid::calculateArea()
{
    double retVal = boost::any_cast<double>(
    bridgesMap_.fetch(trapezoid::AREA).perform(
    { 
        { dataBusKeys::trapezoid::SIDE_FST, sideFst_ },
        { dataBusKeys::trapezoid::SIDE_SND, sideSnd_ },
        { dataBusKeys::trapezoid::LEG_FST, legFst_ },
        { dataBusKeys::trapezoid::LEG_SND, legSnd_ },
        { dataBusKeys::trapezoid::HEIGHT, height_ }
    }));
    return retVal;
}

double CTrapezoid::calculatePerimeter()
{
    double retVal = boost::any_cast<double>(
        bridgesMap_.fetch(trapezoid::PERIMETER).perform(
    {
        { dataBusKeys::trapezoid::SIDE_FST, sideFst_ },
        { dataBusKeys::trapezoid::SIDE_SND, sideSnd_ },
        { dataBusKeys::trapezoid::LEG_FST, legFst_ },
        { dataBusKeys::trapezoid::LEG_SND, legSnd_ },
        { dataBusKeys::trapezoid::HEIGHT, height_ }
    }));
    return retVal;
}

CTrapezoid* CTrapezoid::buildNewObj(double inSideFst, double inSideSnd,
    double inLegFst, double inLegSnd, double inHeight)
{
    return new CTrapezoid(inSideFst, inSideSnd, inLegFst, inLegSnd, inHeight);
}

CTrapezoid* CTrapezoid::buildNewObj(CTrapezoid* inObj)
{
    return new CTrapezoid(*inObj);
}

CTrapezoid* CTrapezoid::buildNewObj()
{
    return new CTrapezoid();
}

std::string CTrapezoid::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << TRAPEZOID << BRACKET_OPEN
        << SIDE << SEPARATOR
        << sideFst_ << COMMA_SPACE
        << sideSnd_ << COMMA_SPACE
        << LEG << SEPARATOR
        << legFst_ << COMMA_SPACE
        << legSnd_ << COMMA_SPACE
        << height_ << BRACKET_CLOSE;

    return retVal.str();
}
