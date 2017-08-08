
#include <Utils/UtilsForMT.hpp>

#include <gtest/gtest.h>
#include <Utils/Utils.hpp>
#include "Logger.hpp"

using namespace defaultVals;
using namespace funs;

namespace assertWrapper
{
CODE getFinalResultCode(std::vector<CODE> inCodes)
{
    bool isLegit = true;
    CODE resultCode = CODE::ERROR;
    int idxOfWrongCode = MINUS_ONE;

    for(int i = 0; i < inCodes.size() && isLegit; i++)
    {
        if(inCodes[i] == CODE::DONE)
        {
            isLegit &= true;
            resultCode = CODE::DONE;
        }
        else
        {
            isLegit &= false;
            resultCode = inCodes[i];
            idxOfWrongCode = i;
        }
    }

    return resultCode;
}

}