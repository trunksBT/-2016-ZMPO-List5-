#pragma once

#include <string>
#include <iostream>

namespace flags
{
constexpr bool PRINT_CTORS = false;
constexpr bool REPLY_COMMAND = true;
}

class Logger
{
private:
    Logger();
    ~Logger();
public:
    Logger& operator<<(std::string inLog);
    static Logger& info();
};
