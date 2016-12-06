#include <Bridges/TrapezoidAreaBridge.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <cmath>

using namespace dataBusKeys;
using namespace defaultVals;
using namespace flags;
using namespace typeLiterals;

CTrapezoidAreaBridge::CTrapezoidAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << TRAPEZOID_AREA_BRIDGE
            << POST_PRINT;
    }
}

const boost::any CTrapezoidAreaBridge::perform(const DataBus& inVal)
{
    double sideFst;
    double sideSnd;
    double legFst;
    double legSnd;

    if (inVal.count(trapezoid::SIDE_FST) &&
        inVal.count(trapezoid::SIDE_SND) &&
        inVal.count(trapezoid::LEG_FST) &&
        inVal.count(trapezoid::LEG_SND))
    {
        sideFst = boost::any_cast<double>(inVal.at(trapezoid::SIDE_FST));
        sideSnd = boost::any_cast<double>(inVal.at(trapezoid::SIDE_SND));
        legFst = boost::any_cast<double>(inVal.at(trapezoid::LEG_FST));
        legSnd = boost::any_cast<double>(inVal.at(trapezoid::LEG_SND));
    }
    else
    {
        Logger()
            << ERROR << SEPARATOR
            << TRAPEZOID
            << NOT_FOUND_IN_DATABUS;
    }

    // is square
    if (double_equals(sideFst, sideSnd) &&
        double_equals(sideFst, legFst) && 
        double_equals(sideFst, legSnd))
    {
        return sideFst*sideFst;
    }

    // is trapezoid or rectangle
    bool predicateOfRectangle1 =
        double_equals(sideFst, legFst) && double_equals(sideSnd, legSnd);
    
    bool predicateOfRectangle2 =
        double_equals(sideFst, legSnd) && double_equals(sideSnd, legFst);

    if (predicateOfRectangle1 || predicateOfRectangle2)
    {
        if (predicateOfRectangle1)
        {
            return sideFst * legSnd;
        }
        else
        {
            return sideFst * legFst;
        }
    }

    double longerSide = (sideFst > sideSnd) ? sideFst : sideSnd;
    double shorterSide = (sideFst < sideSnd) ? sideFst : sideSnd;

    double fstPart = 0.25 * (longerSide + shorterSide) / (longerSide - shorterSide);
    double sndPart = sqrt((longerSide - shorterSide) + legFst + legSnd);
    double thrdPart = sqrt((longerSide - shorterSide) + legFst - legSnd);
    double fourthPart = sqrt((longerSide - shorterSide) - legFst + legSnd);
    double fivethPart = sqrt(-(longerSide - shorterSide) + legFst + legSnd);

    return fstPart * sndPart * thrdPart * fourthPart * fivethPart;
}

IBridge* CTrapezoidAreaBridge::clone()
{
    return new CTrapezoidAreaBridge();
}

CTrapezoidAreaBridge::~CTrapezoidAreaBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << TRAPEZOID_AREA_BRIDGE
            << POST_PRINT;
    }
}