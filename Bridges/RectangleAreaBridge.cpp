#include <Bridges/RectangleAreaBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <cfenv>
#include <boost/math/constants/constants.hpp>
#include <cmath>

using namespace dataBusKeys::circle;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;

boost::any RectangleAreaBridge::perform(const InfoModel& inVal)
{
    if (inVal.count(RADIOUS))
    {
        double radious = boost::any_cast<double>(inVal.at(RADIOUS));
        double retVal = boost::math::constants::pi<double>()*std::pow(radious,2);

        if (static_cast<bool>(std::fetestexcept(FE_OVERFLOW)) ||
            static_cast<bool>(std::fetestexcept(FE_UNDERFLOW)))
        {
            Logger()
                << ERROR << SEPARATOR
                << DOUBLE_OVERFLOW_OR_UNDERFLOW << SPACE
                << POST_PRINT;

            return double();
        }

        return radious*radious;
    }

    Logger()
        << ERROR << SEPARATOR
        << RADIOUS << SPACE
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