#pragma once

#include <string>
#include <vector>
#include <map>
#include "Point.hpp"
#include "Utils.hpp"
#include "Rectangle.h"

class CFlyweight
{
public:
    CFlyweight();
    explicit CFlyweight(int inPointCacheSize, int inShapeCacheSize);
    ~CFlyweight();
public:
    static CODE interpretCommand(std::vector<std::string>& inCommand);
public:
   static void releaseResources();
public:
    static void setPointCacheSize(int inSize);
    static void setShapeCacheSize(int inSize);

    static void updateIsInitializedPointCache(int idx, bool newVal);
    static void updateIsInitializedShapeCache(int idx, bool newVal);

    static void updatePointCache(CShape** newPointCache);
    static void updatePointCache(int idx, CShape* newPointCache);
    static void updateShapeCache(CShape** newShapeCache);
private:
    static void initPointCache(int inCacheSize);
    static void initShapeCache(int inCacheSize);
private:
    static CShape** pointCache_;
    static int pointCacheSize_;
    static std::map<int, bool> pointCacheIsInitialized_;

    static CShape** shapeCache_;
    static int shapeCacheSize_;
    static std::map<int, bool> shapeCacheIsInitialized_;
};

