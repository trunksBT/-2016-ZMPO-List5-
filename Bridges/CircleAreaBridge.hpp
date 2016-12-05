#pragma once

#include <Bridges/IBridge.hpp>

class CCircleAreaBridge : public IBridge
{
public:
    CCircleAreaBridge();
    virtual ~CCircleAreaBridge();
public:
    const boost::any perform(const DataBus& inVal) override;
    IBridge* clone() override;
};