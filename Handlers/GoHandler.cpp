
#include <iostream>

#include "GoHandler.hpp"
#include <Handlers/IShapeHandler.hpp>

#include <Utils/Utils.hpp>
#include <Shapes/Point.hpp>
#include <Flyweight/Flyweight.hpp>
#include <Utils/UtilsForMT.hpp>

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;

CGoHandler::CGoHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{
}

const int CGoHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CGoHandler::getProperTypesOfArgs()
{
    return "si";
}

CODE CGoHandler::checkArgsAndPerform(CShapeWithSize inCache)
{
    if (IHandler::checkTypeAndAmountOfArgs() == CODE::DONE)
    {
        return purePerform(inCache);
    }

    return CODE::ERROR;

}

CODE CGoHandler::purePerform(CShapeWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_SHAPES]);
    int newCacheSize = std::stoi(receivedId);
    int cacheSize = std::get<SIZE>(inCache);

    if (newCacheSize <= ZERO)
    {
        return CODE::ERROR;
    }

    if (cacheSize > 0)
    {
        for (int i = 0; i < cacheSize; i++)
        {
            if (std::get<INITIALIZED_MAP>(inCache)[i])
            {
                delete std::get<ARRAY>(inCache)[i];
            }
        }
        delete[] std::get<ARRAY>(inCache);
    }

    CShape** newTable = new CShape*[newCacheSize];

    CFlyweight::setShapeCacheSize(newCacheSize);
    CFlyweight::updateShapeCache(newTable);
    newTable = nullptr;

    return CODE::DONE;
}

CGoHandler::~CGoHandler()
{

}
