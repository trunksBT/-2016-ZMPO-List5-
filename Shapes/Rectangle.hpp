#pragma once

#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <iostream>

#include <Shapes/Shape.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;

class CRectangle : public CShape
{
public:
    CRectangle();
    CRectangle(double width, double height);
    CRectangle(const CRectangle& inVal);
    virtual ~CRectangle();
public:

public:
    std::string toString() override;
    std::pair<CODE, double> field();
public:
    static CRectangle* buildNewObj(double width, double height);
    static CRectangle* buildNewObj(CRectangle* inObj);
    static CRectangle* buildNewObj();
private:
    double width_;
    double height_;
};
