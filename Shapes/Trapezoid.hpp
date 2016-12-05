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

#include <Bridges/TrapezoidAreaBridge.hpp>
#include <Bridges/TrapezoidPerimeterBridge.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;
using namespace bridgeModelKeys;

class CTrapezoid : public CShape
{
public:
    CTrapezoid(const BridgesModel& inBridges = 
        BridgesModel({ { trapezoid::AREA, new CTrapezoidAreaBridge() }, { trapezoid::PERIMETER, new CTrapezoidPerimeterBridge()} }));
    CTrapezoid(double inSideFst, double inSideSnd, 
        double inLegFst, double inLegSnd, double inHeight, const BridgesModel& inBridges =
        BridgesModel({ { trapezoid::AREA, new CTrapezoidAreaBridge() },{ trapezoid::PERIMETER, new CTrapezoidPerimeterBridge() } }));
    CTrapezoid(const CTrapezoid& inVal);
    virtual ~CTrapezoid();
public:

public:
    std::string toString() override;
    double calculateArea() override;
    double calculatePerimeter() override;
public:
    static CTrapezoid* buildNewObj(
        double inSideFst, double inSideSnd,
        double inLegFst, double inLegSnd, double inHeight);
    static CTrapezoid* buildNewObj(CTrapezoid* inObj);
    static CTrapezoid* buildNewObj();
private:
    double sideFst_;
    double sideSnd_;
    double legFst_;
    double legSnd_;
    double height_;
};
