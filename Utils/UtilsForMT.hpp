#pragma once

#include <utility>
#include <vector>

enum class CODE;


namespace assertWrapper
{
CODE getFinalResultCode(std::vector<CODE> inCodes);
}

