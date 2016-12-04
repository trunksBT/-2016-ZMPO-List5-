#pragma once

#include <map>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <boost/any.hpp>

class IBridge;
using DataBus = std::map<const char*, boost::any>;

using namespace flags;
using namespace typeLiterals;
using namespace defaultVals;

class IBridge
{
public:
    virtual float perform(const DataBus& inVal) = 0;
    virtual ~IBridge()
    {
        if (PRINT_CTORS)
        {
            Logger()
                << DTOR_PRE_PRINT
                << IBRIDGE
                << POST_PRINT;
        }
    }
};