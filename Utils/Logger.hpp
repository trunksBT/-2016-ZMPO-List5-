#pragma once

#include <string>
#include <iostream>

namespace flags
{
constexpr bool PRINT_CTORS = true;
constexpr bool REPLY_COMMAND = true;
}

class Logger
{
private:
public:
    Logger();
    ~Logger();
    Logger& operator<<(std::string inLog);
};
