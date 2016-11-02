#include "stdafx.h"
#include <iostream>

#include "CreateRectPointsHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"
#include "../UtilsForMT.h"

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;

CCreateRectPointsHandler::CCreateRectPointsHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand), IShapeHandler(inCommand), IPointAndRectangleHandler(inCommand)
{}

const int CCreateRectPointsHandler::getProperAmountOfArgs()
{
    return 4;
}

std::string CCreateRectPointsHandler::getProperTypesOfArgs()
{
    return "siii";
}

CODE CCreateRectPointsHandler::checkArgsAndPerform(
    CPointWithSize inPointCache,
    CShapeWithSize inRectangleCache)
{
    if (IHandler::checkTypeAndAmountOfArgs() == CODE::DONE)
    {
        return purePerform(inPointCache, inRectangleCache);
    }
    else
    {
        return CODE::ERROR;
    }
}

CODE CCreateRectPointsHandler::purePerform(
    CPointWithSize inPointCache,
    CShapeWithSize inRectangleCache)
{
    if (IHandler::checkTypeAndAmountOfArgs() == CODE::DONE)
    {
        std::string goalIdxStr(wholeCommand_[idxOf::COPY_TO]);
        int copyToId = std::stoi(goalIdxStr);

        std::string fstPointIdxStr(wholeCommand_[idxOf::POINTS_FST]);
        int pointFstIdx = std::stoi(fstPointIdxStr);

        std::string sndPointIdxStr(wholeCommand_[idxOf::POINT_SND]);
        int pointSndIdx = std::stoi(sndPointIdxStr);

        if (!isProperIdx(copyToId, std::get<SIZE>(inRectangleCache)) ||
            !isProperIdx(pointFstIdx, std::get<SIZE>(inPointCache)) ||
            !isProperIdx(pointSndIdx, std::get<SIZE>(inPointCache)))
        {
            return CODE::ERROR;
        }

        delete std::get<ARRAY>(inRectangleCache)[copyToId];

        std::get<ARRAY>(inRectangleCache)[copyToId] = CRectangle::buildNewObj(
            std::get<ARRAY>(inPointCache)[pointFstIdx],
            std::get<ARRAY>(inPointCache)[pointSndIdx]
        );

        return CODE::DONE;
    }
    else
    {
        return CODE::ERROR;
    }
}

CODE CCreateRectPointsHandler::checkArgsAndPerform(CShapeWithSize inCache)
{
    return CODE::DONE;
}

CODE CCreateRectPointsHandler::purePerform(CShapeWithSize inCache)
{
    return CODE::DONE;
}

CODE CCreateRectPointsHandler::checkArgsAndPerform(CPointWithSize inCache)
{
    return CODE::DONE;
}

CODE CCreateRectPointsHandler::purePerform(CPointWithSize inCache)
{
    return CODE::DONE;
}

CCreateRectPointsHandler::~CCreateRectPointsHandler()
{

}
