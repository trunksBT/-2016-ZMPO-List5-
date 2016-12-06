#pragma once

#include <string>
#include <vector>
#include <map>

#include <Utils/Utils.hpp>
#include <Shapes/Point.hpp>
#include "Shapes/Rectangle.hpp"

class CFlyweight
{
public:
    CFlyweight();
    explicit CFlyweight(int inShapeCacheSize);
    ~CFlyweight();
public:
    static CODE interpretCommand(std::vector<std::string>& inCommand);
public:
    static void releaseResources();
public:
    static void setShapeCacheSize(int inSize);
    static void updateIsInitializedShapeCache(int idx, bool newVal);
    static void updateShapeCache(CShape** newShapeCache);

private:
    static void initShapeCache(int inCacheSize);
private:

    static CShape** shapeCache_;
    static int shapeCacheSize_;
    static std::map<int, bool> shapeCacheIsInitialized_;
};

