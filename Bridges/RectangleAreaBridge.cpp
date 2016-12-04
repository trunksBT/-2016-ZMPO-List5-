#include <Bridges/RectangleAreaBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <cfenv>
#include <boost/math/constants/constants.hpp>
#include <cmath>

using namespace dataBusKeys::rectangle;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;

CRectangleAreaBridge::CRectangleAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << RECTANGLE_AREA_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CRectangleAreaBridge::perform(const InfoModel& inVal)
{
    double sideFst = boost::any_cast<double>(inVal.at(SIDE_FST));
    double sideSnd = boost::any_cast<double>(inVal.at(SIDE_SND));

    return sideFst*sideSnd;
}

IBridge* CRectangleAreaBridge::clone()
{
    return new CRectangleAreaBridge();
}

CRectangleAreaBridge::~CRectangleAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << RECTANGLE_AREA_BRIDGE
            << POST_PRINT;
    }
}