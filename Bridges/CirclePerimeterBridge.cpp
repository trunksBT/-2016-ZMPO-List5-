#include <Bridges/CirclePerimeterBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <boost/math/constants/constants.hpp>

using namespace dataBusKeys;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;


CCirclePerimeterBridge::CCirclePerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << CIRCLE_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CCirclePerimeterBridge::perform(const DataBus& inVal)
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

    return 2*boost::math::constants::pi<double>()*radious;
}

IBridge* CCirclePerimeterBridge::clone()
{
    return new CCirclePerimeterBridge();
}

CCirclePerimeterBridge::~CCirclePerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << CIRCLE_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}