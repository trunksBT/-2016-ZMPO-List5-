#include "stdafx.h"
#include <iostream>

#include "FieldRectHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace cacheIdx;
using namespace tupleIdx;
using namespace typeLiterals;

CFieldRectHandler::CFieldRectHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IShapeHandler(inCommand)
{}

const int CFieldRectHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CFieldRectHandler::getProperTypesOfArgs()
{
    return "si";
}

CODE CFieldRectHandler::checkArgsAndPerform(CShapeWithSize inPointCache)
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

CODE CFieldRectHandler::purePerform(CShapeWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::RECT_GOAL_ID]);
    int idxOrAmount = std::stoi(receivedId);

    if (!isProperIdx(idxOrAmount, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }

    std::pair<CODE, double> fieldWithCode =
        reinterpret_cast<CRectangle*>(std::get<ARRAY>(inCache)[idxOrAmount])->field();

    if (std::get<0>(fieldWithCode) == CODE::ERROR)
    {
        return CODE::ERROR;
    }
    else
    {
        Logger::info() << POINT << SPACE << FIELD << SEPARATOR <<
            std::to_string(std::get<1>(fieldWithCode)) << POST_PRINT;
    }

    return CODE::DONE;
}
