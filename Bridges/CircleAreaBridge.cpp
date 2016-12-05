#include <Bridges/CircleAreaBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <boost/math/constants/constants.hpp>
#include <cmath>

using namespace dataBusKeys;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;

CCircleAreaBridge::CCircleAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << CIRCLE_AREA_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CCircleAreaBridge::perform(const DataBus& inVal)
{
    double radious;

    if (inVal.count(circle::RADIOUS))
    {
        radious = boost::any_cast<double>(inVal.at(circle::RADIOUS));
    }
    else
    {
        Logger()
            << ERROR << SEPARATOR
            << circle::RADIOUS
            << NOT_FOUND_IN_DATABUS;
    }

    return boost::math::constants::pi<double>()*std::pow(radious, 2);
}

IBridge* CCircleAreaBridge::clone()
{
    return new CCircleAreaBridge();
}

CCircleAreaBridge::~CCircleAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << CIRCLE_AREA_BRIDGE
            << POST_PRINT;
    }
}