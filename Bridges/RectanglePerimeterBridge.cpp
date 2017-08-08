#include <Bridges/RectanglePerimeterBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace dataBusKeys;
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

const boost::any CRectanglePerimeterBridge::perform(const DataBus& inVal)
{
    double sideFst;
    double sideSnd;

    if (inVal.count(rectangle::SIDE_FST) && inVal.count(rectangle::SIDE_SND))
    {
        sideFst = boost::any_cast<double>(inVal.at(rectangle::SIDE_FST));
        sideSnd = boost::any_cast<double>(inVal.at(rectangle::SIDE_SND));
    }
    else
    {
        Logger()
            << ERROR << SEPARATOR
            << rectangle::SIDE_FST << OR
            << rectangle::SIDE_SND
            << NOT_FOUND_IN_DATABUS;
    }

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