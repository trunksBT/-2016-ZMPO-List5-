#include <Bridges/TrapezoidPerimeterBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace dataBusKeys;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;


CTrapezoidPerimeterBridge::CTrapezoidPerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << TRAPEZOID_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CTrapezoidPerimeterBridge::perform(const DataBus& inVal)
{
    double sideFst;
    double sideSnd;
    double legFst;
    double legSnd;

    if (inVal.count(trapezoid::SIDE_FST) &&
        inVal.count(trapezoid::SIDE_SND) &&
        inVal.count(trapezoid::LEG_FST) &&
        inVal.count(trapezoid::LEG_SND))
    {
        sideFst = boost::any_cast<double>(inVal.at(trapezoid::SIDE_FST));
        sideSnd = boost::any_cast<double>(inVal.at(trapezoid::SIDE_SND));
        legFst = boost::any_cast<double>(inVal.at(trapezoid::LEG_FST));
        legSnd = boost::any_cast<double>(inVal.at(trapezoid::LEG_SND));
    }
    else
    {
        Logger()
            << ERROR << SEPARATOR
            << TRAPEZOID
            << NOT_FOUND_IN_DATABUS;
    }

    return sideFst + sideSnd + legFst + legSnd;
}

IBridge* CTrapezoidPerimeterBridge::clone()
{
    return new CTrapezoidPerimeterBridge();
}

CTrapezoidPerimeterBridge::~CTrapezoidPerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << TRAPEZOID_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}