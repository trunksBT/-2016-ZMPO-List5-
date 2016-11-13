
#include <Handlers/IShapeHandler.hpp>
#include <iostream>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace funs;

IShapeHandler::IShapeHandler(std::vector<std::string>& inCommand) : IHandler(inCommand)
{
}

IShapeHandler::~IShapeHandler()
{
}
