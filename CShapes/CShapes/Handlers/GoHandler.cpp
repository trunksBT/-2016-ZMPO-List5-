#include "stdafx.h"
#include <iostream>

#include "GoHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"
#include "../UtilsForMT.h"

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;

CGoHandler::CGoHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand), IShapeHandler(inCommand), IPointAndRectangleHandler(inCommand)
{
}

const int CGoHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CGoHandler::getProperTypesOfArgs()
{
    return "sii";
}

CODE CGoHandler::checkArgsAndPerform(
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

CODE CGoHandler::purePerform(
    CPointWithSize inPointCache,
    CShapeWithSize inRectangleCache)
{
    CODE retCode = CODE::ERROR;

    retCode = getFinalResultCode
    ({
        checkArgsAndPerform(inPointCache),
        checkArgsAndPerform(inRectangleCache)
    });

    return retCode;
}

CODE CGoHandler::checkArgsAndPerform(CShapeWithSize inCache)
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

CODE CGoHandler::checkArgsAndPerform(CPointWithSize inCache)
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

CODE CGoHandler::purePerform(CPointWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_POINTS]);
    int idxOrAmount = std::stoi(receivedId);
    int cacheSize = std::get<SIZE>(inCache);

    if (idxOrAmount < ZERO)
    {
        return CODE::ERROR;
    }
    else if (idxOrAmount == ZERO)
    {
        return CODE::DONE;
    }
    else
    {
        int newSize = cacheSize + idxOrAmount;
        CShape** newTable = new CShape*[newSize];

        for (int i = 0; i < cacheSize; i++)
        {
            newTable[i] = std::get<ARRAY>(inCache)[i];
        }

        int cursor = cacheSize;
        for (int i = 0; i < idxOrAmount; i++, cursor++)
        {
            CFlyweight::updateIsInitializedPointCache(cursor, true);
            newTable[cursor] = CPoint::buildNewObj(DEFAULT_FST_AXIS_VAL, DEFAULT_FST_AXIS_VAL);
        }
        CFlyweight::setPointCacheSize(newSize);
        CFlyweight::updatePointCache(newTable);
        newTable = nullptr;
    }
    return CODE::DONE;
}

CODE CGoHandler::purePerform(CShapeWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_SHAPES]);
    int idxOrAmount = std::stoi(receivedId);
    int cacheSize = std::get<SIZE>(inCache);

    if (idxOrAmount < ZERO)
    {
        return CODE::ERROR;
    }
    else if (idxOrAmount == ZERO)
    {
        return CODE::DONE;
    }
    else
    {
        int newSize = cacheSize + idxOrAmount;
        CShape** newTable = new CShape*[newSize];

        for (int i = 0; i < cacheSize; i++)
        {
            newTable[i] = std::get<ARRAY>(inCache)[i];
        }

        int cursor = cacheSize;
        for (int i = 0; i < idxOrAmount; i++, cursor++)
        {
            CFlyweight::updateIsInitializedShapeCache(cursor, true);
            newTable[cursor] = CRectangle::buildNewObj(
                DEFAULT_FST_AXIS_VAL,
                DEFAULT_FST_AXIS_VAL,
                DEFAULT_SND_AXIS_VAL,
                DEFAULT_SND_AXIS_VAL
            );
        }
        CFlyweight::setShapeCacheSize(newSize);
        CFlyweight::updateShapeCache(newTable);
        newTable = nullptr;
    }
    return CODE::DONE;
}

CGoHandler::~CGoHandler()
{

}
