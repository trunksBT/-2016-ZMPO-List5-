#include "stdafx.h"
#include <iostream>

#include "IPointAndRectangleHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;

IPointAndRectangleHandler::IPointAndRectangleHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand), IShapeHandler(inCommand)
{}

IPointAndRectangleHandler::~IPointAndRectangleHandler()
{

}
