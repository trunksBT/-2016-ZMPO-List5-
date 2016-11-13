
#include <iostream>

#include "CreatePointCopyHandler.hpp"
#include <Utils/Utils.hpp>
#include <Shapes/Point.hpp>
#include <Flyweight/Flyweight.hpp>

using namespace defaultVals;
using namespace funs;
using namespace cacheIdx;
using namespace tupleIdx;

CCreatePointCopyHandler::CCreatePointCopyHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand)
{}

const int CCreatePointCopyHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CCreatePointCopyHandler::getProperTypesOfArgs()
{
    return "sii";
}

CODE CCreatePointCopyHandler::checkArgsAndPerform(CPointWithSize inPointCache)
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


CODE CCreatePointCopyHandler::purePerform(CPointWithSize inCache)
{
    std::string copyToIdStr(wholeCommand_[idxOf::COPY_TO]);
    int copyToId = std::stoi(copyToIdStr);

    std::string copyFromIdStr(wholeCommand_[idxOf::COPY_FROM]);
    int copyFromId = std::stoi(copyFromIdStr);

    if (!isProperIdx(copyToId, std::get<SIZE>(inCache)) ||
        !isProperIdx(copyFromId, std::get<SIZE>(inCache)) )
    {
        return CODE::ERROR;
    }

    if (copyToId == copyFromId)
    {
        return CODE::DONE;
    }

    delete std::get<ARRAY>(inCache)[copyToId];
    std::get<ARRAY>(inCache)[copyToId] =
        CPoint::buildNewObj(std::get<ARRAY>(inCache)[copyFromId]);

    return CODE::DONE;
}
