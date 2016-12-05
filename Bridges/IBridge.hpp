#pragma once

#include <map>
#include <boost/any.hpp>

class IBridge;
using DataBus = std::map<std::string, boost::any>;

class IBridge
{
public:
    virtual const boost::any perform(const DataBus& inVal) = 0;
    virtual IBridge* clone() = 0;
    virtual ~IBridge() = default;
};