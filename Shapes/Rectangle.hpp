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

#include <Bridges/RectangleAreaBridge.hpp>
#include <Bridges/RectanglePerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys::rectangle;

class CRectangle : public CShape
{
public:
    CRectangle(const BridgesModel& inBridges = 
        BridgesModel({ {AREA, new CRectangleAreaBridge() }, {PERIMETER, new CRectanglePerimeterBridge()} }));
    CRectangle(double width, double height, const BridgesModel& inBridges =
        BridgesModel({ { AREA, new CRectangleAreaBridge() },{ PERIMETER, new CRectanglePerimeterBridge() } }));
    CRectangle(const CRectangle& inVal);
    virtual ~CRectangle();
public:

public:
    std::string toString() override;
    double calculateArea() override;
    double calculatePerimeter() override;
public:
    static CRectangle* buildNewObj(double width, double height);
    static CRectangle* buildNewObj(CRectangle* inObj);
    static CRectangle* buildNewObj();
private:
    double width_;
    double height_;
};
