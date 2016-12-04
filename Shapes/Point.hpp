#pragma once

#include <string>
#include <vector>
#include <Shapes/Shape.hpp>

class CPoint : public CShape
{
public:
    explicit CPoint(double xAxis, double yAxis);
    CPoint(const CPoint& inVal);
    virtual ~CPoint();
public:
    double getX() const;
    double getY() const;
    std::string toString() override;
public:
    void setX(double newX);
    void setY(double newY);
public:
    static CPoint* buildNewObj(double xAxis, double yAxis);
    static CPoint* buildNewObj(CPoint* inObj);

private:
    void deepCopy(const CPoint& inVal);
    void deallocateMemory();
private:
    double* xAxis_;
    double* yAxis_;
};
