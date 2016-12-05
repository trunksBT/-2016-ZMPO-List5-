#include <Bridges/TrapezoidAreaBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <cmath>

using namespace dataBusKeys;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;

CTrapezoidAreaBridge::CTrapezoidAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << TRAPEZOID_AREA_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CTrapezoidAreaBridge::perform(const DataBus& inVal)
{
    double sideFst;
    double sideSnd;
    double legFst;
    double legSnd;
    double height;

    if (inVal.count(trapezoid::SIDE_FST) &&
        inVal.count(trapezoid::SIDE_SND) &&
        inVal.count(trapezoid::LEG_FST) &&
        inVal.count(trapezoid::LEG_SND) &&
        inVal.count(trapezoid::HEIGHT))
    {
        sideFst = boost::any_cast<double>(inVal.at(trapezoid::SIDE_FST));
        sideSnd = boost::any_cast<double>(inVal.at(trapezoid::SIDE_SND));
        legFst = boost::any_cast<double>(inVal.at(trapezoid::LEG_FST));
        legSnd = boost::any_cast<double>(inVal.at(trapezoid::LEG_SND));
        height = boost::any_cast<double>(inVal.at(trapezoid::HEIGHT));
    }
    else
    {
        Logger()
            << ERROR << SEPARATOR
            << TRAPEZOID
            << NOT_FOUND_IN_DATABUS;
    }

    Logger()
        << ERROR << SEPARATOR
        << std::string("Not Implemented Yet");

    return 0.0;
}

IBridge* CTrapezoidAreaBridge::clone()
{
    return new CTrapezoidAreaBridge();
}

CTrapezoidAreaBridge::~CTrapezoidAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << TRAPEZOID_AREA_BRIDGE
            << POST_PRINT;
    }
}