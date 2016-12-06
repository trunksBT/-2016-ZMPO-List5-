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

#include <Bridges/CircleAreaBridge.hpp>
#include <Bridges/CirclePerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys;

class CCircle : public CShape
{
public:
    CCircle(const BridgesModel& inBridges = 
        BridgesModel({ { circle::AREA, new CCircleAreaBridge() }, { circle::PERIMETER, new CCirclePerimeterBridge()} }));
    CCircle(double inRadious, const BridgesModel& inBridges =
        BridgesModel({ { circle::AREA, new CCircleAreaBridge() },{ circle::PERIMETER, new CCirclePerimeterBridge() } }));
    CCircle(const CCircle& inVal);
    virtual ~CCircle();
public:

public:
    std::string toString() override;
    double calculateArea() override;
    bool isPossibleToCreate() override;
    double calculatePerimeter() override;
public:
    static CCircle* buildNewObj(double inRadious);
    static CCircle* buildNewObj(CCircle* inObj);
    static CCircle* buildNewObj();
private:
    double radious_;
};
