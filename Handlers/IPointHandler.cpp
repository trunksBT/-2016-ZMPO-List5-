
#include "IPointHandler.hpp"
#include <iostream>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace funs;

IPointHandler::IPointHandler(std::vector<std::string>& inCommand) : IHandler(inCommand)
{
}

IPointHandler::~IPointHandler()
{
}
