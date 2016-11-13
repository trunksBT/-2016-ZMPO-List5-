#include <iostream>
#include <Flyweight/Flyweight.hpp>

#include <Utils/Utils.hpp>
#include <Utils/UtilsForMT.hpp>
#include <Utils/Logger.hpp>

#include <Handlers/GoHandler.hpp>
#include <Handlers/CreatePointHandler.hpp>
#include <Handlers/SetPointHandler.hpp>
#include <Handlers/CreatePointCopyHandler.hpp>
#include <Handlers/GetPointXHandler.hpp>
#include <Handlers/GetPointYHandler.hpp>
#include <Handlers/CreateRectPointsHandler.hpp>
#include <Handlers/CreateRectDoubleHandler.hpp>
#include <Handlers/CreateRectCopyHandler.hpp>
#include <Handlers/CreateRectDefaultHandler.hpp>
#include <Handlers/FieldRectHandler.hpp>
#include <Handlers/ShowRectHandler.hpp>
#include <Handlers/RemoveAllHandler.hpp>
#include <Handlers/RemoveHandler.hpp>
#include <Handlers/PrintAllHandler.hpp>
#include <Handlers/HelpHandler.hpp>

using namespace defaultVals;
using namespace messageLiterals;
using namespace funs;

CShape** CFlyweight::pointCache_;
int CFlyweight::pointCacheSize_;
std::map<int, bool> CFlyweight::pointCacheIsInitialized_;

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
        CPointWithSize pairedPointCache =
        std::make_tuple(
            reinterpret_cast<CPoint**>(pointCache_),
            pointCacheSize_,
            pointCacheIsInitialized_);
;

        CShapeWithSize pairedShapeCache = 
        std::make_tuple(
            shapeCache_,
            shapeCacheSize_,
            shapeCacheIsInitialized_ );

        if (command == GO)
        {
            IPointAndRectangleHandler* evaluate = new CGoHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache, pairedShapeCache);
        }
        else if(command == CREATE_POINT)
        {
            IPointHandler* evaluate = new CCreatePointHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache);
        }
        else if(command == CREATE_POINT_COPY)
        {
            IPointHandler* evaluate = new CCreatePointCopyHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache);
        }
        else if (command == SET_POINT)
        {
            IPointHandler* evaluate = new CSetPointHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache);
        }
        else if (command == GET_POINT_X)
        {
            IPointHandler* evaluate = new CGetPointXHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache);
        }
        else if (command == GET_POINT_Y)
        {
            IPointHandler* evaluate = new CGetPointYHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache);
        }
        else if (command == CREATE_RECT_POINTS)
        {
            IPointAndRectangleHandler* evaluate = new CCreateRectPointsHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache, pairedShapeCache);
        }
        else if (command == CREATE_RECT_DOUBLE)
        {
            IShapeHandler* evaluate = new CCreateRectDoubleHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CREATE_RECT_DEFAULT)
        {
            IShapeHandler* evaluate = new CCreateRectDefaultHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CREATE_RECT_COPY)
        {
            IShapeHandler* evaluate = new CCreateRectCopyHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == FIELD_RECT)
        {
            IShapeHandler* evaluate = new CFieldRectHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == PRINT_ALL)
        {
            IPointAndRectangleHandler* evaluate = new CPrintAllHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache, pairedShapeCache);
        }
        else if (command == SHOW_RECT)
        {
            IShapeHandler* evaluate = new CShowRectHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == HELP)
        {
            IShapeHandler* evaluate = new CHelpHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
        }
        else if (command == CLOSE)
        {
            releaseResources();
            returnedCode = CODE::CLOSE;
        }

    }

    return returnedCode;
}

#pragma region ********** CTORS_DTORS **********

void CFlyweight::releaseResources()
{
    for (int i = 0; i < pointCacheSize_; i++)
    {
        if (pointCacheIsInitialized_[i] && pointCache_[i] != nullptr)
        {
            delete pointCache_[i];
            pointCache_[i] = nullptr;
        }
    }
    delete[] pointCache_;
    pointCache_ = nullptr;
    pointCacheSize_ = ZERO;
    pointCacheIsInitialized_.clear();

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

void CFlyweight::initPointCache(int inCacheSize)
{
    if (inCacheSize >= ZERO)
    {
        pointCacheSize_ = inCacheSize;
        pointCache_ = nullptr;
        for (int i = 0; i < pointCacheSize_; i++)
        {
            pointCacheIsInitialized_[i] = false;
        }

        pointCache_ = new CShape*[pointCacheSize_];
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
    initPointCache(ZERO);
    initPointCache(ZERO);
}

CFlyweight::CFlyweight(int inPointCacheSize, int inShapeCacheSize)
{
    initPointCache(inPointCacheSize);
    initPointCache(inShapeCacheSize);
}

CFlyweight::~CFlyweight()
{
    CFlyweight::releaseResources();
}

void CFlyweight::setPointCacheSize(int inSize)
{
    pointCacheSize_ = inSize;
}
void CFlyweight::setShapeCacheSize(int inSize)
{
    shapeCacheSize_ = inSize;
}

void CFlyweight::updateIsInitializedPointCache(int idx, bool newVal)
{
    pointCacheIsInitialized_[idx] = newVal;
}

void CFlyweight::updateIsInitializedShapeCache(int idx, bool newVal)
{
    shapeCacheIsInitialized_[idx] = newVal;
}

void CFlyweight::updatePointCache(CShape** newPointCache)
{
    pointCache_ = newPointCache;
}

void CFlyweight::updateShapeCache(CShape** newShapeCache)
{
    shapeCache_ = newShapeCache;
}

void CFlyweight::updatePointCache(int idx, CShape* newPointCache)
{
    pointCache_[idx] = newPointCache;
}


# pragma endregion
