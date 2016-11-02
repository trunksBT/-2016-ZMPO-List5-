#include "stdafx.h"
#include <iostream>

#include "SetPointHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace funs;
using namespace cacheIdx;
using namespace tupleIdx;

CSetPointHandler::CSetPointHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand)
{}

const int CSetPointHandler::getProperAmountOfArgs()
{
    return 4;
}

std::string CSetPointHandler::getProperTypesOfArgs()
{
    return "sidd";
}

CODE CSetPointHandler::checkArgsAndPerform(CPointWithSize inPointCache)
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

CODE CSetPointHandler::purePerform(CPointWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_FOR_CREATE]);
    int idxOrAmount = std::stoi(receivedId);

    std::string receivedXAxis(wholeCommand_[idxOf::X_AXIS_VAL]);
    double xAxis = std::stod(receivedXAxis);

    std::string receivedYAxis(wholeCommand_[idxOf::Y_AXIS_VAL]);
    double yAxis = std::stod(receivedYAxis);

    if (!isProperIdx(idxOrAmount, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }

    std::get<ARRAY>(inCache)[idxOrAmount]->setX(xAxis);
    std::get<ARRAY>(inCache)[idxOrAmount]->setY(yAxis);

    return CODE::DONE;
}
