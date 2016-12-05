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

#include <Bridges/SquareAreaBridge.hpp>
#include <Bridges/SquarePerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys;

class CSquare : public CShape
{
public:
    CSquare(const BridgesModel& inBridges = 
        BridgesModel({ { square::AREA, new CSquareAreaBridge() }, { square::PERIMETER, new CSquarePerimeterBridge()} }));
    CSquare(double inSide, const BridgesModel& inBridges =
        BridgesModel({ { square::AREA, new CSquareAreaBridge() },{ square::PERIMETER, new CSquarePerimeterBridge() } }));
    CSquare(const CSquare& inVal);
    virtual ~CSquare();
public:

public:
    std::string toString() override;
    double calculateArea() override;
    double calculatePerimeter() override;
public:
    static CSquare* buildNewObj(double inSide);
    static CSquare* buildNewObj(CSquare* inObj);
    static CSquare* buildNewObj();
private:
    double side_;
};
