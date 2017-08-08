#pragma once

#include <Bridges/IBridge.hpp>

class CTriangleAreaBridge : public IBridge
{
public:
    CTriangleAreaBridge();
    virtual ~CTriangleAreaBridge();
public:
    const boost::any perform(const DataBus& inVal) override;
    IBridge* clone() override;
};