#pragma once

#include <Bridges/IBridge.hpp>

class CTrianglePerimeterBridge : public IBridge
{
public:
    CTrianglePerimeterBridge();
    virtual ~CTrianglePerimeterBridge();
public:
    const boost::any perform(const DataBus& inVal) override;
    IBridge* clone() override;
};