#include <Bridges/SquarePerimeterBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace dataBusKeys;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;


CSquarePerimeterBridge::CSquarePerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << RECTANGLE_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CSquarePerimeterBridge::perform(const DataBus& inVal)
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

    return 4 * side;
}

IBridge* CSquarePerimeterBridge::clone()
{
    return new CSquarePerimeterBridge();
}

CSquarePerimeterBridge::~CSquarePerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << RECTANGLE_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}