#pragma once

#include <Bridges/IBridge.hpp>

class CSquarePerimeterBridge : public IBridge
{
public:
    CSquarePerimeterBridge();
    virtual ~CSquarePerimeterBridge();
public:
    const boost::any perform(const DataBus& inVal) override;
    IBridge* clone() override;
};