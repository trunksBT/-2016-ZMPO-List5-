#pragma once

#include <Bridges/IBridge.hpp>

class CRectangleAreaBridge : public IBridge
{
public:
    CRectangleAreaBridge();
    virtual ~CRectangleAreaBridge();
public:
    const boost::any perform(const InfoModel& inVal) override;
    IBridge* clone() override;
};