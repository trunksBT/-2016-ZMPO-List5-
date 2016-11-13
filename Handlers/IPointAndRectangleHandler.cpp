
#include <iostream>

#include "IPointAndRectangleHandler.hpp"
#include <Utils/Utils.hpp>
#include <Shapes/Point.hpp>
#include <Flyweight/Flyweight.hpp>

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;

IPointAndRectangleHandler::IPointAndRectangleHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand), IShapeHandler(inCommand)
{}

IPointAndRectangleHandler::~IPointAndRectangleHandler()
{

}
