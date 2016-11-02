#include "stdafx.h"
#include <iostream>

#include "CreateRectCopyHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace funs;
using namespace cacheIdx;
using namespace tupleIdx;

CCreateRectCopyHandler::CCreateRectCopyHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IShapeHandler(inCommand)
{}

const int CCreateRectCopyHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CCreateRectCopyHandler::getProperTypesOfArgs()
{
    return "sii";
}

CODE CCreateRectCopyHandler::checkArgsAndPerform(CShapeWithSize inPointCache)
{
    if (IHandler::checkTypeAndAmountOfArgs() == CODE::DONE)
    {
        return purePerform(inPointCache);
    }
    else
    {
        return CODE::ERROR;
    }
}

CODE CCreateRectCopyHandler::purePerform(CShapeWithSize inCache)
{
    std::string copyToIdStr(wholeCommand_[idxOf::COPY_TO]);
    int copyToId = std::stoi(copyToIdStr);

    std::string copyFromIdStr(wholeCommand_[idxOf::COPY_FROM]);
    int copyFromId = std::stoi(copyFromIdStr);

    if (!isProperIdx(copyToId, std::get<SIZE>(inCache)) ||
        !isProperIdx(copyFromId, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }

    if (copyToId == copyFromId)
    {
        return CODE::DONE;
    }

    delete std::get<ARRAY>(inCache)[copyToId];
    std::get<ARRAY>(inCache)[copyToId] =
        CRectangle::buildNewObj(
            reinterpret_cast<CRectangle*>(std::get<ARRAY>(inCache)[copyFromId]));

    return CODE::DONE;
}

CCreateRectCopyHandler::~CCreateRectCopyHandler()
{

}

