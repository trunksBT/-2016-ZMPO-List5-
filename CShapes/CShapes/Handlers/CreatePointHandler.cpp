#include "stdafx.h"
#include <iostream>

#include "CreatePointHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace funs;
using namespace cacheIdx;
using namespace tupleIdx;

CCreatePointHandler::CCreatePointHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand)
{
}

const int CCreatePointHandler::getProperAmountOfArgs()
{
    return 4;
}

std::string CCreatePointHandler::getProperTypesOfArgs()
{
    return "sidd";
}

CODE CCreatePointHandler::checkArgsAndPerform(CPointWithSize inPointCache)
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


CODE CCreatePointHandler::purePerform(CPointWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_FOR_CREATE]);
    int idxOrAmount = std::stoi(receivedId);

    std::string receivedXAxis(wholeCommand_[idxOf::X_AXIS_VAL]);
    double xAxis = std::stod(receivedXAxis);

    std::string receivedYAxis(wholeCommand_[idxOf::Y_AXIS_VAL]);
    double yAxis = std::stod(receivedYAxis);

    if(!isProperIdx(idxOrAmount, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }

    CPoint* objOnSelectedIdx = std::get<ARRAY>(inCache)[idxOrAmount];
    if(objOnSelectedIdx != nullptr)
    {
        delete objOnSelectedIdx;
    }
    std::get<ARRAY>(inCache)[idxOrAmount] = CPoint::buildNewObj(xAxis, yAxis);

    return CODE::DONE;
}
