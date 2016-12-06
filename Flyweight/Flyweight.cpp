#include <iostream>
#include <Flyweight/Flyweight.hpp>

#include <Utils/Utils.hpp>
#include <Utils/UtilsForMT.hpp>
#include <Utils/Logger.hpp>

#include <Handlers/GoHandler.hpp>
#include <Handlers/CreateRectDoubleHandler.hpp>
#include <Handlers/CreateSquareDoubleHandler.hpp>
#include <Handlers/CreateCircleDoubleHandler.hpp>
#include <Handlers/CreateTriangleDoubleHandler.hpp>
#include <Handlers/CreateTrapezoidDoubleHandler.hpp>

#include <Handlers/AreaHandler.hpp>
#include <Handlers/AreasHandler.hpp>
#include <Handlers/PerimeterHandler.hpp>
#include <Handlers/PerimetersHandler.hpp>
#include <Handlers/PrintAllHandler.hpp>

using namespace defaultVals;
using namespace messageLiterals;
using namespace tupleIdx;
using namespace typeLiterals;
using namespace funs;

CShape** CFlyweight::shapeCache_;
int CFlyweight::shapeCacheSize_;
std::map<int, bool> CFlyweight::shapeCacheIsInitialized_;

CODE CFlyweight::interpretCommand(std::vector<std::string>& inCommand)
{
    CODE returnedCode = CODE::ERROR;
    {
        if (inCommand.size() == ZERO)
        {
            return CODE::ERROR;
        }

        std::string command(inCommand[idxOf::COMMAND]);

        CShapeWithSize pairedShapeCache = 
        std::forward_as_tuple(
            shapeCache_,
            shapeCacheSize_,
            shapeCacheIsInitialized_);

        IShapeHandler* evaluate = nullptr;

        if (command == GO)
        {
            evaluate = new CGoHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CREATE_RECT_DOUBLE)
        {
            evaluate = new CCreateRectDoubleHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CREATE_SQUARE_DOUBLE)
        {
            evaluate = new CCreateSquareDoubleHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CREATE_CIRCLE_DOUBLE)
        {
            evaluate = new CCreateCircleDoubleHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CREATE_TRIANGLE_DOUBLE)
        {
            evaluate = new CCreateTriangleDoubleHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CREATE_TRAPEZOID_DOUBLE)
        {
            evaluate = new CCreateTrapezoidDoubleHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CALCULATE_AREA)
        {
            evaluate = new CAreaHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CALCULATE_AREAS)
        {
            evaluate = new CAreasHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CALCULATE_PERIMETER)
        {
            evaluate = new CPerimeterHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CALCULATE_PERIMETERS)
        {
            evaluate = new CPerimetersHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == PRINT_ALL)
        {
            evaluate = new CPrintAllHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CLOSE)
        {
            releaseResources();
            returnedCode = CODE::CLOSE;
        }
        delete evaluate;
    }

    return returnedCode;
}

#pragma region ********** CTORS_DTORS **********

void CFlyweight::releaseResources()
{
    for (int i = 0; i < shapeCacheSize_; i++)
    {
        if ( shapeCacheIsInitialized_[i] && shapeCache_[i] != nullptr )
        {
            delete shapeCache_[i];
            shapeCache_[i] = nullptr;
        }
    }
    delete[] shapeCache_;
    shapeCache_ = nullptr;
    shapeCacheSize_ = ZERO;
    shapeCacheIsInitialized_.clear();
}

double CFlyweight::sumPerimeters(bool& isNotPossible)
{
    double retVal = ZERO;

    CShapeWithSize pairedShapeCache =
        std::forward_as_tuple(
            shapeCache_,
            shapeCacheSize_,
            shapeCacheIsInitialized_);

    std::map<int, bool> isInitializedMap = std::get<INITIALIZED_MAP>(pairedShapeCache);

    for (int i = 0; i < shapeCacheSize_; i++)
    {
        CShape* tempObj = std::get<ARRAY>(pairedShapeCache)[i];
        if (isInitializedMap[i])
        {
            if (tempObj->isPossibleToCreate())
            {
                retVal += tempObj->calculatePerimeter();
            }
            else
            {
                Logger()
                    << ERROR << SEPARATOR
                    << SHAPE_CAN_NOT_EXIST
                    << POST_PRINT;

                isNotPossible = true;
                return retVal;
            }
        }
        else
        {
            retVal += ZERO;
        }
    }

    return retVal;

}

double CFlyweight::sumAreas(bool& isNotPossible)
{
    double retVal = ZERO;

    CShapeWithSize pairedShapeCache =
        std::forward_as_tuple(
            shapeCache_,
            shapeCacheSize_,
            shapeCacheIsInitialized_);

    Logger() << SHAPES << POST_PRINT;
    std::map<int, bool> isInitializedMap = std::get<INITIALIZED_MAP>(pairedShapeCache);

    for (int i = 0; i < shapeCacheSize_; i++)
    {
        CShape* tempObj = std::get<ARRAY>(pairedShapeCache)[i];
        if (isInitializedMap[i] )
        {
            if (tempObj->isPossibleToCreate())
            {
                retVal += tempObj->calculateArea();
            }
            else
            {
                Logger()
                    << ERROR << SEPARATOR
                    << SHAPE_CAN_NOT_EXIST
                    << POST_PRINT;

                isNotPossible = true;
                return retVal;
            }
        }
        else
        {
            retVal += ZERO;
        }
    }

    return retVal;
}

void CFlyweight::printAll()
{
    CShapeWithSize pairedShapeCache =
        std::forward_as_tuple(
            shapeCache_,
            shapeCacheSize_,
            shapeCacheIsInitialized_);

    Logger() << SHAPES << POST_PRINT;
    std::map<int, bool> isInitializedMap = std::get<INITIALIZED_MAP>(pairedShapeCache);

    for (int i = 0; i < shapeCacheSize_; i++)
    {
        if (isInitializedMap[i])
        {
            Logger() << std::get<ARRAY>(pairedShapeCache)[i]->toString();
        }
        else
        {
            Logger() << toString(CODE::NOT_INITIALIZED);
        }
        Logger() << POST_PRINT;
    }
}

void CFlyweight::initShapeCache(int inCacheSize)
{
    if (inCacheSize >= ZERO)
    {
        shapeCacheSize_ = inCacheSize;
        shapeCache_ = nullptr;
        for (int i = 0; i < shapeCacheSize_; i++)
        {
            shapeCacheIsInitialized_[i] = false;
        }

        shapeCache_ = new CShape*[shapeCacheSize_];
    }
}

CFlyweight::CFlyweight()
{
    initShapeCache(ZERO);
}

CFlyweight::CFlyweight(int inShapeCacheSize)
{
    initShapeCache(inShapeCacheSize);
}

CFlyweight::~CFlyweight()
{
    CFlyweight::releaseResources();
}

void CFlyweight::setShapeCacheSize(int inSize)
{
    shapeCacheSize_ = inSize;
}


void CFlyweight::updateIsInitializedShapeCache(int idx, bool newVal)
{
    shapeCacheIsInitialized_[idx] = newVal;
}

void CFlyweight::updateShapeCache(CShape** newShapeCache)
{
    shapeCache_ = newShapeCache;
}

# pragma endregion
