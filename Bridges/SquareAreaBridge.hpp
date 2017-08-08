#pragma once

#include <Bridges/IBridge.hpp>

class CSquareAreaBridge : public IBridge
{
public:
    CSquareAreaBridge();
    virtual ~CSquareAreaBridge();
public:
    const boost::any perform(const DataBus& inVal) override;
    IBridge* clone() override;
};