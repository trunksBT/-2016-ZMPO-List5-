#pragma once

#include <string>
class CShape
{
public:
    CShape();
    virtual ~CShape();
    virtual std::string toString() = 0;
    virtual std::string getType() = 0;
};

