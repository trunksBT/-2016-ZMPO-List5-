
#include <iostream>

#include "PrintAllHandler.hpp"
#include <Utils/Utils.hpp>
#include <Shapes/Point.hpp>
#include <Flyweight/Flyweight.hpp>
#include <Utils/UtilsForMT.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;
using namespace typeLiterals;

CPrintAllHandler::CPrintAllHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{}

const int CPrintAllHandler::getProperAmountOfArgs()
{
    return 1;
}

std::string CPrintAllHandler::getProperTypesOfArgs()
{
    return "s";
}

CODE CPrintAllHandler::checkArgsAndPerform(CShapeWithSize inCache)
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

CODE CPrintAllHandler::purePerform(CShapeWithSize inCache)
{
    int cacheSize = std::get<SIZE>(inCache);

    Logger() << SHAPES << POST_PRINT;
    std::map<int, bool> isInitializedMap = std::get<INITIALIZED_MAP>(inCache);

    for (int i = 0; i < cacheSize; i++)
    {
        if (isInitializedMap[i])
        {
            Logger() << std::get<ARRAY>(inCache)[i]->toString();
        }
        else
        {
            Logger() << toString(CODE::NOT_INITIALIZED);
        }
        Logger() << POST_PRINT;
    }

    return CODE::DONE;
}
