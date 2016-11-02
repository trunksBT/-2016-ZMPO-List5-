#include "stdafx.h"
#include <iostream>

#include "HelpHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"

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
        Logger::info() << it << POST_PRINT;
    }
    return CODE::DONE;
}

CHelpHandler::~CHelpHandler()
{
}

