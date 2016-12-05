#include <Bridges/TriangleAreaBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <cmath>

using namespace dataBusKeys;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;

CTriangleAreaBridge::CTriangleAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << TRIANGLE_AREA_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CTriangleAreaBridge::perform(const DataBus& inVal)
{
    double sideFst;
    double sideSnd;
    double sideThrd;

    if (inVal.count(triangle::SIDE_FST) &&
        inVal.count(triangle::SIDE_SND) && 
        inVal.count(triangle::SIDE_THRD) )
    {
        sideFst = boost::any_cast<double>(inVal.at(triangle::SIDE_FST));
        sideSnd = boost::any_cast<double>(inVal.at(triangle::SIDE_SND));
        sideThrd = boost::any_cast<double>(inVal.at(triangle::SIDE_THRD));
    }
    else
    {
        Logger()
            << ERROR << SEPARATOR
            << triangle::SIDE_FST
            << NOT_FOUND_IN_DATABUS;
    }

    // Heron's formula
    double p = (sideFst + sideSnd + sideThrd)/2;
    return sqrt(p*(p-sideFst)*(p - sideSnd)*(p - sideThrd));
}

IBridge* CTriangleAreaBridge::clone()
{
    return new CTriangleAreaBridge();
}

CTriangleAreaBridge::~CTriangleAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << TRIANGLE_AREA_BRIDGE
            << POST_PRINT;
    }
}