#include "stdafx.h"
#include "IShapeHandler.h"
#include <iostream>
#include "../Utils.hpp"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;

IShapeHandler::IShapeHandler(std::vector<std::string>& inCommand) : IHandler(inCommand)
{
}

IShapeHandler::~IShapeHandler()
{
}
