#pragma once

#include <Shapes/Point.hpp>

namespace communication
{
std::vector<std::string> performLexer(std::string inCommand);
std::vector<std::string> receiveAndLexCommandFromUser();
};

