
#include <Shapes/Shape.hpp>
#include <sstream>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;

CShape::CShape(const BridgesModel& inBridges)
    : bridgesMap_(inBridges)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << SHAPE
            << POST_PRINT;
    }
}

CShape::CShape()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << SHAPE
            << POST_PRINT;
    }
}


CShape::~CShape()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << SHAPE
            << POST_PRINT;
    }
}
