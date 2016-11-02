#include "stdafx.h"
#include "IPointHandler.h"
#include <iostream>
#include "../Utils.hpp"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;

IPointHandler::IPointHandler(std::vector<std::string>& inCommand) : IHandler(inCommand)
{
}

IPointHandler::~IPointHandler()
{
}
