#include <Bridges/RectanglePerimeterBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace dataBusKeys::rectangle;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;


CRectanglePerimeterBridge::CRectanglePerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << RECTANGLE_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CRectanglePerimeterBridge::perform(const InfoModel& inVal)
{
    double sideFst = boost::any_cast<double>(inVal.at(SIDE_FST));
    double sideSnd = boost::any_cast<double>(inVal.at(SIDE_SND));

    return 2*sideFst + 2*sideSnd;
}

IBridge* CRectanglePerimeterBridge::clone()
{
    return new CRectanglePerimeterBridge();
}

CRectanglePerimeterBridge::~CRectanglePerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << RECTANGLE_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}