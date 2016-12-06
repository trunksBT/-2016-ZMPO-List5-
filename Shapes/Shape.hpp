#pragma once

#include <string>
#include <map>

#include <Bridges/IBridge.hpp>
#include <Bridges/BridgesModel.hpp>

class CShape
{
public:
    CShape();
    CShape(const BridgesModel& inBridgesMap);
    virtual ~CShape();
public:
    virtual std::string toString() = 0;
    virtual bool isPossibleToCreate() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
protected:
    BridgesModel bridgesMap_;
};

