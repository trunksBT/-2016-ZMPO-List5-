#include "stdafx.h"
#include <iostream>

#include "GetPointYHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace cacheIdx;
using namespace tupleIdx;
using namespace typeLiterals;

CGetPointYHandler::CGetPointYHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand)
{}

const int CGetPointYHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CGetPointYHandler::getProperTypesOfArgs()
{
    return "si";
}

CODE CGetPointYHandler::checkArgsAndPerform(CPointWithSize inPointCache)
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

CODE CGetPointYHandler::purePerform(CPointWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_POINTS]);
    int idxOrAmount = std::stoi(receivedId);

    if (!isProperIdx(idxOrAmount, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }

    Logger::info() << POINT << SPACE << Y << SEPARATOR <<
        std::to_string(std::get<ARRAY>(inCache)[idxOrAmount]->getY()) << POST_PRINT;

    return CODE::DONE;
}
