#include "AreaHandler.hpp"

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

CAreaHandler::CAreaHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{}

const int CAreaHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CAreaHandler::getProperTypesOfArgs()
{
    return "si";
}

CODE CAreaHandler::checkArgsAndPerform(CShapeWithSize inPointCache)
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

CODE CAreaHandler::purePerform(CShapeWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::RECT_GOAL_ID]);
    int idxOrAmount = std::stoi(receivedId);

    if (!isProperIdx(idxOrAmount, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }

    double fieldWithCode =
        reinterpret_cast<CRectangle*>(std::get<ARRAY>(inCache)[idxOrAmount])->calculateArea();

        if (static_cast<bool>(std::fetestexcept(FE_OVERFLOW)) ||
            static_cast<bool>(std::fetestexcept(FE_UNDERFLOW)))

    if (static_cast<bool>(std::fetestexcept(FE_OVERFLOW)) ||
        static_cast<bool>(std::fetestexcept(FE_UNDERFLOW)))
    {
        return CODE::ERROR;
    }
    else
    {
        Logger() << POINT << SPACE << FIELD << SEPARATOR <<
            std::to_string(fieldWithCode) << POST_PRINT;
    }

    return CODE::DONE;
}
