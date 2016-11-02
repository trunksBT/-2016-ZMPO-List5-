#include "stdafx.h"
#include <iostream>

#include "CreateRectDoubleHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"
#include "../UtilsForMT.h"

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;

CCreateRectDoubleHandler::CCreateRectDoubleHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IShapeHandler(inCommand)
{}

const int CCreateRectDoubleHandler::getProperAmountOfArgs()
{
    return 6;
}

std::string CCreateRectDoubleHandler::getProperTypesOfArgs()
{
    return "sidddd";
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
    int copyToIdx = std::stoi(goalIdxStr);

    std::string pointFstXIdxStr(wholeCommand_[idxOf::POINT_FST_X]);
    double pointFstXIdx = std::stod(pointFstXIdxStr);

    std::string pointFstYIdxStr(wholeCommand_[idxOf::POINT_FST_Y]);
    double pointFstYIdx = std::stod(pointFstYIdxStr);

    std::string pointSndXIdxStr(wholeCommand_[idxOf::POINT_SND_X]);
    double pointSndXIdx = std::stod(pointSndXIdxStr);

    std::string pointSndYIdxStr(wholeCommand_[idxOf::POINT_SND_Y]);
    double pointSndYIdx = std::stod(pointSndYIdxStr);

    if (!isProperIdx(copyToIdx, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }


    //// TODO FORGOTTEN CHECK OF PROPER ARGS WTS?

    delete std::get<ARRAY>(inCache)[copyToIdx];
    std::get<ARRAY>(inCache)[copyToIdx] = CRectangle::buildNewObj(
        pointFstXIdx,
        pointFstYIdx,
        pointSndXIdx,
        pointSndYIdx
    );

    return CODE::DONE;
}

CCreateRectDoubleHandler::~CCreateRectDoubleHandler()
{

}
