#include "stdafx.h"
#include <iostream>

#include "ShowRectHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"
#include "../UtilsForMT.h"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;
using namespace typeLiterals;

CShowRectHandler::CShowRectHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IShapeHandler(inCommand)
{}

const int CShowRectHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CShowRectHandler::getProperTypesOfArgs()
{
    return "si";
}

CODE CShowRectHandler::checkArgsAndPerform(CShapeWithSize inCache)
{
    if (checkTypeAndAmountOfArgs() == CODE::DONE)
    {
        return purePerform(inCache);
    }
    else
    {
        return CODE::ERROR;
    }
}

CODE CShowRectHandler::purePerform(CShapeWithSize inCache)
{
    int cacheSize = std::get<SIZE>(inCache);
    std::string goalIdxStr(wholeCommand_[idxOf::COPY_TO]);
    int copyToId = std::stoi(goalIdxStr);

    if (!isProperIdx(copyToId, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }

    Logger::info() << SHAPE << POST_PRINT;
    Logger::info() << std::get<ARRAY>(inCache)[copyToId]->toString() << POST_PRINT;

    return CODE::DONE;
}
