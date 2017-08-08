#pragma once

#include <Bridges/IBridge.hpp>

class CTrapezoidAreaBridge : public IBridge
{
public:
    CTrapezoidAreaBridge();
    virtual ~CTrapezoidAreaBridge();
public:
    const boost::any perform(const DataBus& inVal) override;
    IBridge* clone() override;
};