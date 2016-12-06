
#include <iostream>

#include "CreateTriangleDoubleHandler.hpp"
#include <Utils/Utils.hpp>
#include <Flyweight/Flyweight.hpp>
#include <Utils/UtilsForMT.hpp>

#include <Shapes/Triangle.hpp>

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;
using namespace idxOf::triangle;

CCreateTriangleDoubleHandler::CCreateTriangleDoubleHandler(std::vector<std::string>& inCommand)
    : IShapeHandler(inCommand)
{}

const int CCreateTriangleDoubleHandler::getProperAmountOfArgs()
{
    return 5;
}

std::string CCreateTriangleDoubleHandler::getProperTypesOfArgs()
{
    return "siddd";
}

CODE CCreateTriangleDoubleHandler::checkArgsAndPerform(CShapeWithSize inCache)
{
    if (IHandler::checkTypeAndAmountOfArgs() == CODE::DONE)
    {
        return purePerform(inCache);
    }
    else
    {
        return CODE::ERROR;
    }
}

CODE CCreateTriangleDoubleHandler::purePerform(CShapeWithSize inCache)
{
    std::string goalIdxStr(wholeCommand_[idxOf::RECT_GOAL_ID]);
    int newTriangleIdx = std::stoi(goalIdxStr);

    std::string sideFstStr(wholeCommand_[SIDE_FST_IDX]);
    double sideFst = std::stod(sideFstStr);

    std::string sideSndStr(wholeCommand_[SIDE_SND_IDX]);
    double sideSnd = std::stod(sideSndStr);

    std::string sideThrdStr(wholeCommand_[SIDE_THRD_IDX]);
    double sideThrd = std::stod(sideThrdStr);

    if (!isTriangleProper(sideFst, sideSnd, sideThrd))
    {
        Logger()
            << ERROR << SEPARATOR
            << THIS_SHAPE_CANNOT_EXIST
            << POST_PRINT;
        
        return CODE::ERROR;
    }

    if (!isProperIdx(newTriangleIdx, std::get<SIZE>(inCache)))
    {
        return CODE::ERROR;
    }
    
    if (std::get<INITIALIZED_MAP>(inCache)[newTriangleIdx])
    {
        delete std::get<ARRAY>(inCache)[newTriangleIdx];
    }

    std::get<ARRAY>(inCache)[newTriangleIdx] = CTriangle::buildNewObj(
        sideFst, sideSnd, sideThrd);

    std::get<INITIALIZED_MAP>(inCache)[newTriangleIdx] = true;

    return CODE::DONE;
}
