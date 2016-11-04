#include "stdafx.h"
#include "Logger.h"

using namespace flags;

Logger::Logger()
{}

Logger::~Logger()
{}

Logger& Logger::operator<<(std::string inLog)
{
    static Logger member;
    std::cout << inLog;
    return member;
}
