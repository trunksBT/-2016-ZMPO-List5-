#include <Bridges/SquareAreaBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <cfenv>
#include <boost/math/constants/constants.hpp>
#include <cmath>

using namespace dataBusKeys;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;

CSquareAreaBridge::CSquareAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << RECTANGLE_AREA_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CSquareAreaBridge::perform(const DataBus& inVal)
{
    double side;

    if (inVal.count(square::SIDE))
    {
        side = boost::any_cast<double>(inVal.at(square::SIDE));
    }
    else
    {
        Logger()
            << ERROR << SEPARATOR
            << square::SIDE
            << NOT_FOUND_IN_DATABUS;
    }

    return side*side;
}

IBridge* CSquareAreaBridge::clone()
{
    return new CSquareAreaBridge();
}

CSquareAreaBridge::~CSquareAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << RECTANGLE_AREA_BRIDGE
            << POST_PRINT;
    }
}