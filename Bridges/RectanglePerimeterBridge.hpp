#pragma once

#include <Bridges/IBridge.hpp>

class CRectanglePerimeterBridge : public IBridge
{
public:
    CRectanglePerimeterBridge();
    virtual ~CRectanglePerimeterBridge();
public:
    const boost::any perform(const DataBus& inVal) override;
    IBridge* clone() override;
};