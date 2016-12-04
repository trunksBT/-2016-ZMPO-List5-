#pragma once

#include <map>
#include <boost/any.hpp>

class IBridge;
using InfoModel = std::map<const char*, boost::any>;

class IBridge
{
public:
    virtual boost::any perform(const InfoModel& inVal) = 0;
    virtual ~IBridge();
};