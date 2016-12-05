#include "PerimeterHandler.hpp"

#include <iostream>
#include <cfenv>

#include <Utils/Utils.hpp>
#include <Shapes/Point.hpp>
#include <Flyweight/Flyweight.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace funs;
using namespace cacheIdx;
using namespace tupleIdx;
using namespace typeLiterals;

CPerimeterHandler::CPerimeterHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{}

const int CPerimeterHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CPerimeterHandler::getProperTypesOfArgs()
{
    return "si";
}

CODE CPerimeterHandler::checkArgsAndPerform(CShapeWithSize inPointCache)
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

CODE CPerimeterHandler::purePerform(CShapeWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::RECT_GOAL_ID]);
    int idxOrAmount = std::stoi(receivedId);

    if (!isProperIdx(idxOrAmount, std::get<SIZE>(inCache)))
    {
        if (PRINT_ERRORS)
        {
            Logger() << PERIMETER_HANDLER << SEPARATOR << ERROR << SEPARATOR <<
                std::to_string(idxOrAmount) << SEPARATOR << TO_BIG_IDX_FOR_CACHE << POST_PRINT;
        }
        return CODE::ERROR;
    }

    if (!std::get<INITIALIZED_MAP>(inCache)[idxOrAmount])
    {
        if (PRINT_ERRORS)
        {
            Logger() << PERIMETER_HANDLER << SEPARATOR << ERROR << SEPARATOR <<
                std::to_string(idxOrAmount) << SEPARATOR << NOT_FOUND_IN_CACHE << POST_PRINT;
        }
        return CODE::ERROR;
    }

    double perimeterWithCode = std::get<ARRAY>(inCache)[idxOrAmount]->calculatePerimeter();

    if (static_cast<bool>(std::fetestexcept(FE_OVERFLOW)) ||
        static_cast<bool>(std::fetestexcept(FE_UNDERFLOW)))
    {
        return CODE::ERROR;
    }
    else
    {
        Logger() << PERIMETER_HANDLER << SEPARATOR <<
            std::to_string(perimeterWithCode) << POST_PRINT;
    }

    return CODE::DONE;
}
