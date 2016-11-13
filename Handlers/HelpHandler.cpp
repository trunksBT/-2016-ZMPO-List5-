
#include <iostream>

#include "HelpHandler.hpp"
#include <Utils/Utils.hpp>
#include <Shapes/Point.hpp>
#include <Flyweight/Flyweight.hpp>

using namespace defaultVals;
using namespace funs;
using namespace cacheIdx;
using namespace tupleIdx;

CHelpHandler::CHelpHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IShapeHandler(inCommand)
{}

const int CHelpHandler::getProperAmountOfArgs()
{
    return 1;
}

std::string CHelpHandler::getProperTypesOfArgs()
{
    return "s";
}

CODE CHelpHandler::checkArgsAndPerform(CShapeWithSize inPointCache)
{
    purePerform(inPointCache);
    return CODE::DONE;
}


CODE CHelpHandler::purePerform(CShapeWithSize inCache)
{
    for (auto& it : fullCommands::all)
    {
        Logger() << it << POST_PRINT;
    }
    return CODE::DONE;
}

CHelpHandler::~CHelpHandler()
{
}

