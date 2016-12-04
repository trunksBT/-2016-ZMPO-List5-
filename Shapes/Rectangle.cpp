
#include "Rectangle.hpp"
#include "Point.hpp"
#include <Utils/Utils.hpp>
#include <iostream>
#include <limits>
#include <sstream>
#include <Utils/Logger.hpp>
#include <cmath>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;

CRectangle::CRectangle() 
    : width_(ZERO), height_(ZERO)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_DEF_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::CRectangle(double width, double height)
    : width_(width), height_(height)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_ARG1_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::CRectangle(const CRectangle& inVal)
    : width_(inVal.width_), height_(inVal.height_)
{
    if (PRINT_CTORS)
    {
        Logger()
            << CTOR_COPY_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

CRectangle::~CRectangle()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
}

std::pair<CODE,double> CRectangle::field()
{
    //double fstX = objectFst_.getX();
    //double fstY = objectFst_.getY();

    //double sndX = objectSnd_.getX();
    //double sndY = objectSnd_.getY();

    //double segmentFstLength = 0.0;
    //double segmentSndLength = 0.0;
    //double finalField = 0.0;
    //if (isSegmentToBig(fstX, sndX) && isSegmentToBig(fstY, sndY))
    //{
    //    return{ CODE::ERROR, 0.0 };
    //}
    //else
    //{
    //    segmentFstLength = std::abs(fstX - sndX);
    //    segmentSndLength = std::abs(fstY - sndY);
    //}

    //if (isDoubleOverflow(segmentFstLength, segmentSndLength))
    //{
    //    return{ CODE::ERROR, 0.0 };
    //}
    //else
    //{
    //    finalField = segmentFstLength * segmentSndLength;
    //}

    return { CODE::DONE, 3.0 };
    //return std::pair<CODE, double>();
}

CRectangle* CRectangle::buildNewObj(double width, double height)
{
    return new CRectangle(width, height);
}

CRectangle* CRectangle::buildNewObj(CRectangle* inObj)
{
    return new CRectangle(*inObj);
}

CRectangle* CRectangle::buildNewObj()
{
    return new CRectangle();
}

std::string CRectangle::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << RECTANGLE << BRACKET_OPEN
        << WIDTH << SEPARATOR
        << width_
        << COMMA_SPACE
        << HEIGHT << SEPARATOR
        << height_
        << BRACKET_CLOSE;

    return retVal.str();
}

