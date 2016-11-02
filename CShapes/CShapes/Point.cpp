#include "stdafx.h"
#include "Point.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include "Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;

CPoint::CPoint(double xAxis, double yAxis) : CShape()
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_ARG1_PRE_PRINT
            << POINT
            << POST_PRINT;
    }

    xAxis_ = new double(xAxis);
    yAxis_ = new double(yAxis);

    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_ARG1_PRE_PRINT
            << X << SEPARATOR << std::to_string(*xAxis_)
            << COMMA_SPACE
            << Y << SEPARATOR << std::to_string(*yAxis_)
            << POST_PRINT;
    }
}

CPoint::CPoint(const CPoint& inVal)
{
    deepCopy(inVal);

    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_COPY_PRE_PRINT
            << X << SEPARATOR << std::to_string(*xAxis_)
            << COMMA_SPACE
            << Y << SEPARATOR << std::to_string(*yAxis_)
            << POST_PRINT;
    }
}

void CPoint::deepCopy(const CPoint& inVal)
{
    xAxis_ = new double(*inVal.xAxis_);
    yAxis_ = new double(*inVal.yAxis_);
}

CPoint::~CPoint()
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << DTOR_PRE_PRINT
            << POINT
            << X << SEPARATOR << std::to_string(*xAxis_)
            << COMMA_SPACE
            << Y << SEPARATOR << std::to_string(*yAxis_)
            << POST_PRINT;
    }
    deallocateMemory();
}

CPoint* CPoint::buildNewObj(double xAxis, double yAxis)
{
    return new CPoint(xAxis, yAxis);
}

CPoint* CPoint::buildNewObj(CPoint* inObj)
{
    return new CPoint(*inObj);
}

void CPoint::deallocateMemory()
{
    delete xAxis_;
    delete yAxis_;
}

void CPoint::setX(double newX)
{
    *xAxis_ = newX;
}

void CPoint::setY(double newY)
{
    *yAxis_ = newY;
}

double CPoint::getX() const
{
    return double(*xAxis_);
}

double CPoint::getY() const
{
    return double(*yAxis_);
}

std::string CPoint::getType()
{
    return POINT;
}

std::string CPoint::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << POINT << BRACKET_OPEN
        << X << SEPARATOR << std::to_string(*xAxis_)
        << COMMA_SPACE
        << Y << SEPARATOR << std::to_string(*yAxis_)
        << BRACKET_CLOSE;

    return retVal.str();
}

