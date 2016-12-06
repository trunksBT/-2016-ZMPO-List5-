#pragma once

#include <map>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <iostream>

#include <Shapes/Shape.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

#include <Bridges/TriangleAreaBridge.hpp>
#include <Bridges/TrianglePerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys;

class CTriangle : public CShape
{
public:
    CTriangle(const BridgesModel& inBridges = 
        BridgesModel({ { triangle::AREA, new CTriangleAreaBridge() }, { triangle::PERIMETER, new CTrianglePerimeterBridge()} }));
    CTriangle(double inSideFst, double inSideSnd, double inSideThrd, const BridgesModel& inBridges =
        BridgesModel({ { triangle::AREA, new CTriangleAreaBridge() },{ triangle::PERIMETER, new CTrianglePerimeterBridge() } }));
    CTriangle(const CTriangle& inVal);
    virtual ~CTriangle();
public:
    std::string toString() override;
    bool isPossibleToCreate() override;
    double calculateArea() override;
    double calculatePerimeter() override;
public:
    static CTriangle* buildNewObj(double inSideFst, double inSideSnd, double inSideThrd);
    static CTriangle* buildNewObj(CTriangle* inObj);
    static CTriangle* buildNewObj();
private:
    bool isPossibleToCreate(double inSideFst, double inSideSnd, double inSideThrd);
private:
    double sideFst_;
    double sideSnd_;
    double sideThrd_;
};
