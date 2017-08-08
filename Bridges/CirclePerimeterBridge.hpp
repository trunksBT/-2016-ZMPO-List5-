#pragma once

#include <Bridges/IBridge.hpp>

class CCirclePerimeterBridge : public IBridge
{
public:
    CCirclePerimeterBridge();
    virtual ~CCirclePerimeterBridge();
public:
    const boost::any perform(const DataBus& inVal) override;
    IBridge* clone() override;
};