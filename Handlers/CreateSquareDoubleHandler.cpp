
#include <iostream>

#include "CreateSquareDoubleHandler.hpp"
#include <Utils/Utils.hpp>
#include <Flyweight/Flyweight.hpp>
#include <Utils/UtilsForMT.hpp>

#include <Shapes/Square.hpp>

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;
using namespace idxOf::rectangle;

CCreateSquareDoubleHandler::CCreateSquareDoubleHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{}

const int CCreateSquareDoubleHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CCreateSquareDoubleHandler::getProperTypesOfArgs()
{
    return "sid";
}

CODE CCreateSquareDoubleHandler::checkArgsAndPerform(CShapeWithSize inCache)
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

CODE CCreateSquareDoubleHandler::purePerform(CShapeWithSize inCache)
{
    std::string goalIdxStr(wholeCommand_[idxOf::RECT_GOAL_ID]);
    int newSquareIdx = std::stoi(goalIdxStr);

    std::string sideStr(wholeCommand_[SIDE_FST_IDX]);
    double side = std::stod(sideStr);

    if (!isProperIdx(newSquareIdx, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }
    
    if (std::get<INITIALIZED_MAP>(inCache)[newSquareIdx])
    {
        delete std::get<ARRAY>(inCache)[newSquareIdx];
    }

    std::get<ARRAY>(inCache)[newSquareIdx] = CSquare::buildNewObj(side);

    std::get<INITIALIZED_MAP>(inCache)[newSquareIdx] = true;

    return CODE::DONE;
}
