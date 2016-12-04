#include "IBridge.hpp"

#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace flags;
using namespace typeLiterals;
using namespace defaultVals;

IBridge::~IBridge()
{
    if (PRINT_CTORS)
    {
        Logger()
            << DTOR_PRE_PRINT
            << IBRIDGE
            << POST_PRINT;
    }
}