#include "stdafx.h"
#include "Rectangle.h"
#include "Point.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include "Logger.h"
#include <cmath>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;

CRectangle::CRectangle() 
    : objectFst_(0, 0), objectSnd_(1, 1)
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_DEF_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::CRectangle(CPoint* inPointFst, CPoint* inPointSnd)
    : objectFst_(*inPointFst), objectSnd_(*inPointSnd)
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_ARG1_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::CRectangle(double fstX, double fstY, double sndX, double sndY)
    : objectFst_(fstX, fstY), objectSnd_(sndX, sndY)
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_ARG1_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::CRectangle(const CRectangle& inVal)
    : objectFst_(inVal.objectFst_), objectSnd_(inVal.objectSnd_)
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_COPY_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::~CRectangle()
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << DTOR_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

std::pair<CODE,double> CRectangle::field()
{
    double fstX = objectFst_.getX();
    double fstY = objectFst_.getY();

    double sndX = objectSnd_.getX();
    double sndY = objectSnd_.getY();

    double segmentFstLength = 0.0;
    double segmentSndLength = 0.0;
    double finalField = 0.0;
    if (isSegmentToBig(fstX, sndX) && isSegmentToBig(fstY, sndY))
    {
        return{ CODE::ERROR, 0.0 };
    }
    else
    {
        segmentFstLength = abs(fstX - sndX);
        segmentSndLength = abs(fstY - sndY);
    }

    if (isDoubleOverflow(segmentFstLength, segmentSndLength))
    {
        return{ CODE::ERROR, 0.0 };
    }
    else
    {
        finalField = segmentFstLength * segmentSndLength;
    }

    return{ CODE::DONE, finalField };
}

CRectangle* CRectangle::buildNewObj(CPoint* inPointFst, CPoint* inPointSnd)
{
    return new CRectangle(inPointFst, inPointSnd);
}

CRectangle* CRectangle::buildNewObj(double fstX, double fstY, double sndX, double sndY)
{
    return new CRectangle(fstX, fstY, sndX, sndY);
}

CRectangle* CRectangle::buildNewObj(CRectangle* inObj)
{
    return new CRectangle(*inObj);
}

CRectangle* CRectangle::buildNewObj()
{
    return new CRectangle();
}

std::string CRectangle::getType()
{
    return RECTANGLE;
}

std::string CRectangle::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << RECTANGLE << BRACKET_OPEN
        << objectFst_.toString()
        << COMMA_SPACE
        << objectSnd_.toString()
        << BRACKET_CLOSE;

    return retVal.str();
}

double CRectangle::fstGetX()
{
    return objectFst_.getX();
}

double CRectangle::fstGetY()
{
    return objectFst_.getY();
}

double CRectangle::sndGetX()
{
    return objectSnd_.getX();
}

double CRectangle::sndGetY()
{
    return objectSnd_.getY();
}

