
#include <iostream>

#include "CreateTrapezoidDoubleHandler.hpp"
#include <Utils/Utils.hpp>
#include <Flyweight/Flyweight.hpp>
#include <Utils/UtilsForMT.hpp>

#include <Shapes/Trapezoid.hpp>

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;
using namespace idxOf::trapezoid;

CCreateTrapezoidDoubleHandler::CCreateTrapezoidDoubleHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{}

const int CCreateTrapezoidDoubleHandler::getProperAmountOfArgs()
{
    return 6;
}

std::string CCreateTrapezoidDoubleHandler::getProperTypesOfArgs()
{
    return "sidddd";
}

CODE CCreateTrapezoidDoubleHandler::checkArgsAndPerform(CShapeWithSize inCache)
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

CODE CCreateTrapezoidDoubleHandler::purePerform(CShapeWithSize inCache)
{
    std::string goalIdxStr(wholeCommand_[idxOf::RECT_GOAL_ID]);
    int newTrapezoidIdx = std::stoi(goalIdxStr);

    std::string sideFstStr(wholeCommand_[SIDE_FST_IDX]);
    double sideFst = std::stod(sideFstStr);

    std::string sideSndStr(wholeCommand_[SIDE_SND_IDX]);
    double sideSnd = std::stod(sideSndStr);

    std::string legFstStr(wholeCommand_[LEG_FST_IDX]);
    double legFst = std::stod(legFstStr);

    std::string legSndStr(wholeCommand_[LEG_SND_IDX]);
    double legSnd = std::stod(legSndStr);

    if (!isProperIdx(newTrapezoidIdx, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }
    
    if (std::get<INITIALIZED_MAP>(inCache)[newTrapezoidIdx])
    {
        delete std::get<ARRAY>(inCache)[newTrapezoidIdx];
    }

    std::get<ARRAY>(inCache)[newTrapezoidIdx] = CTrapezoid::buildNewObj(
        sideFst, sideSnd, legFst, legSnd
);

    std::get<INITIALIZED_MAP>(inCache)[newTrapezoidIdx] = true;

    return CODE::DONE;
}
