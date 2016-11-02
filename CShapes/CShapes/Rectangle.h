#pragma once

#include <string>
#include <vector>
#include "Shape.h"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include "Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;

class CPoint;
class CRectangle : public CShape
{
public:
    CRectangle();
    CRectangle(CPoint* inPointFst, CPoint* inPointSnd);
    CRectangle(double fstX, double fstY, double sndX, double sndY);
    CRectangle(const CRectangle& inVal);
    virtual ~CRectangle();
public:
    double fstGetX();
    double fstGetY();
    double sndGetX();
    double sndGetY();
public:
    std::string toString() override;
    std::string getType() override;
    std::pair<CODE, double> field();
public:
    static CRectangle* buildNewObj(CPoint* inPointFst, CPoint* inPointSnd);
    static CRectangle* buildNewObj(double fstX, double fstY, double sndX, double sndY);
    static CRectangle* buildNewObj(CRectangle* inObj);
    static CRectangle* buildNewObj();
private:
    CPoint objectFst_;
    CPoint objectSnd_;
};
