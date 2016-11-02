#include "stdafx.h"
#include <iostream>

#include "CreateRectDefaultHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"
#include "../UtilsForMT.h"

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;

CCreateRectDefaultHandler::CCreateRectDefaultHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IShapeHandler(inCommand)
{}

const int CCreateRectDefaultHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CCreateRectDefaultHandler::getProperTypesOfArgs()
{
    return "si";
}

CODE CCreateRectDefaultHandler::checkArgsAndPerform(CShapeWithSize inCache)
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

CODE CCreateRectDefaultHandler::purePerform(CShapeWithSize inCache)
{
    std::string goalIdxStr(wholeCommand_[idxOf::RECT_GOAL_ID]);
    int copyToIdx = std::stoi(goalIdxStr);

    if (!isProperIdx(copyToIdx, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }

    delete std::get<ARRAY>(inCache)[copyToIdx];
    std::get<ARRAY>(inCache)[copyToIdx] = CRectangle::buildNewObj();
    return CODE::DONE;
}

CCreateRectDefaultHandler::~CCreateRectDefaultHandler()
{

}
