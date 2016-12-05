#pragma once

#include <Bridges/IBridge.hpp>

class CTrapezoidPerimeterBridge : public IBridge
{
public:
    CTrapezoidPerimeterBridge();
    virtual ~CTrapezoidPerimeterBridge();
public:
    const boost::any perform(const DataBus& inVal) override;
    IBridge* clone() override;
};