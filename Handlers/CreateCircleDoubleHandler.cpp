
#include <iostream>

#include "CreateCircleDoubleHandler.hpp"
#include <Utils/Utils.hpp>
#include <Flyweight/Flyweight.hpp>
#include <Utils/UtilsForMT.hpp>

#include <Shapes/Circle.hpp>

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;
using namespace idxOf::rectangle;

CCreateCircleDoubleHandler::CCreateCircleDoubleHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{}

const int CCreateCircleDoubleHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CCreateCircleDoubleHandler::getProperTypesOfArgs()
{
    return "sid";
}

CODE CCreateCircleDoubleHandler::checkArgsAndPerform(CShapeWithSize inCache)
{
    if (IHandler::checkTypeAndAmountOfArgs() == CODE::DONE)
    {
        return purePerform(inCache);
    }
    else
    {
        return CODE::ERROR;
    }
}

CODE CCreateCircleDoubleHandler::purePerform(CShapeWithSize inCache)
{
    std::string goalIdxStr(wholeCommand_[idxOf::RECT_GOAL_ID]);
    int newCircleIdx = std::stoi(goalIdxStr);

    std::string radiousStr(wholeCommand_[SIDE_FST_IDX]);
    double radious = std::stod(radiousStr);

    if (!isProperIdx(newCircleIdx, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }
    
    if (std::get<INITIALIZED_MAP>(inCache)[newCircleIdx])
    {
        delete std::get<ARRAY>(inCache)[newCircleIdx];
    }

    std::get<ARRAY>(inCache)[newCircleIdx] = CCircle::buildNewObj(radious);

    std::get<INITIALIZED_MAP>(inCache)[newCircleIdx] = true;

    return CODE::DONE;
}
