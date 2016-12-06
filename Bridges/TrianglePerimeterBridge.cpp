#include <Bridges/TrianglePerimeterBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace dataBusKeys;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;


CTrianglePerimeterBridge::CTrianglePerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << TRIANGLE_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CTrianglePerimeterBridge::perform(const DataBus& inVal)
{
    double sideFst;
    double sideSnd;
    double sideThrd;

    if (inVal.count(triangle::SIDE_FST) &&
        inVal.count(triangle::SIDE_SND) &&
        inVal.count(triangle::SIDE_THRD))
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
    return sideFst + sideSnd + sideThrd;
}

IBridge* CTrianglePerimeterBridge::clone()
{
    return new CTrianglePerimeterBridge();
}

CTrianglePerimeterBridge::~CTrianglePerimeterBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << TRIANGLE_PERIMETER_BRIDGE
            << POST_PRINT;
    }
}