
#include <iostream>

#include "CreateRectDoubleHandler.hpp"
#include <Utils/Utils.hpp>
#include <Shapes/Point.hpp>
#include <Flyweight/Flyweight.hpp>
#include <Utils/UtilsForMT.hpp>

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;
using namespace idxOf::rectangle;

CCreateRectDoubleHandler::CCreateRectDoubleHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{}

const int CCreateRectDoubleHandler::getProperAmountOfArgs()
{
    return 4;
}

std::string CCreateRectDoubleHandler::getProperTypesOfArgs()
{
    return "sidd";
}

CODE CCreateRectDoubleHandler::checkArgsAndPerform(CShapeWithSize inCache)
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

CODE CCreateRectDoubleHandler::purePerform(CShapeWithSize inCache)
{
    std::string goalIdxStr(wholeCommand_[idxOf::RECT_GOAL_ID]);
    int newRectIdx = std::stoi(goalIdxStr);

    std::string sideFstStr(wholeCommand_[SIDE_FST_IDX]);
    double sideFst = std::stod(sideFstStr);

    std::string sideSndStr(wholeCommand_[SIDE_SND_IDX]);
    double sideSnd = std::stod(sideSndStr);

    if (!isProperIdx(newRectIdx, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }
    
    if (std::get<INITIALIZED_MAP>(inCache)[newRectIdx])
    {
        delete std::get<ARRAY>(inCache)[newRectIdx];
    }

    std::get<ARRAY>(inCache)[newRectIdx] = CRectangle::buildNewObj(
        sideFst,
        sideSnd
    );

    std::get<INITIALIZED_MAP>(inCache)[newRectIdx] = true;

    return CODE::DONE;
}
