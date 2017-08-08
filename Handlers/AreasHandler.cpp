#include "AreasHandler.hpp"

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

CAreasHandler::CAreasHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{}

const int CAreasHandler::getProperAmountOfArgs()
{
    return 1;
}

std::string CAreasHandler::getProperTypesOfArgs()
{
    return "s";
}

CODE CAreasHandler::checkArgsAndPerform(CShapeWithSize inPointCache)
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

CODE CAreasHandler::purePerform(CShapeWithSize inCache)
{
    int sizeOfCache = std::get<SIZE>(inCache);

    for (int i = 0; i < sizeOfCache; i++)
    {
        if (std::get<INITIALIZED_MAP>(inCache)[i])
        {
            CShape *tempShape = std::get<ARRAY>(inCache)[i];
            if (tempShape->isPossibleToCreate())
            {
                double areaWithCode = tempShape->calculateArea();

                if (static_cast<bool>(std::fetestexcept(FE_OVERFLOW)) ||
                    static_cast<bool>(std::fetestexcept(FE_UNDERFLOW)))
                {
                    Logger() << typeLiterals::AREA_HANDLER << SEPARATOR <<
                        ERROR << OVERFLOW_OR_UNDERFLOW << SEPARATOR
                        << tempShape->toString() << SEPARATOR <<
                        std::to_string(areaWithCode) << POST_PRINT;
                }
                else
                {
                    Logger() << typeLiterals::AREA_HANDLER << SEPARATOR
                        << tempShape->toString() << SEPARATOR <<
                        std::to_string(areaWithCode) << POST_PRINT;
                }
            }
            else
            {
                Logger() << typeLiterals::AREA_HANDLER << SEPARATOR
                    << tempShape->toString() << SEPARATOR <<
                    ERROR << SHAPE_CAN_NOT_EXIST << SEPARATOR << 
                    std::to_string(ZERO) << POST_PRINT;
            }
        }
        else
        {
            Logger() << typeLiterals::AREA_HANDLER << SEPARATOR <<
                ERROR << SHAPE << SEPARATOR << NOT_FOUND_IN_CACHE <<
                std::to_string(ZERO) << POST_PRINT;
        }
    }

    return CODE::DONE;
}
