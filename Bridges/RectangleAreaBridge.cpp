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

boost::any RectangleAreaBridge::perform(const InfoModel& inVal)
{
    if (inVal.count(SIDE_FST) && inVal.count(SIDE_SND))
    {
        double sideFst = boost::any_cast<double>(inVal.at(SIDE_FST));
        double sideSnd = boost::any_cast<double>(inVal.at(SIDE_SND));

        return sideFst*sideSnd;
    }

    Logger()
        << ERROR << SEPARATOR
        << SIDE_FST << COMMA_SPACE
        << SIDE_SND << COMMA_SPACE
        << NOT_FOUND_IN_IM
        << POST_PRINT;

    return double();
}

RectangleAreaBridge::~RectangleAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << CIRCLE_AREA_BRIDGE
            << POST_PRINT;
    }
}