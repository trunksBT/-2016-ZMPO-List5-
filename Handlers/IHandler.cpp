
#include "IHandler.hpp"
#include <iostream>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace funs;
using namespace flags;

IHandler::IHandler(std::vector<std::string>& inCommand)
{
    wholeCommand_ = inCommand;
    if (REPLY_COMMAND)
    {
        Logger() << PRE_PRINT << wholeCommand_[idxOf::COMMAND] << POST_PRINT;
    }
}

CODE IHandler::checkTypeAndAmountOfArgs()
{
    if (!isProperAmmountOfArgs(wholeCommand_, getProperAmountOfArgs()))
    {
        return CODE::ERROR;
    }
    
    if (!isProperTypeOfArgs(wholeCommand_, getProperTypesOfArgs()))
    {
        return CODE::ERROR;
    }

    return CODE::DONE;
}

IHandler::~IHandler()
{
    Logger() << POST_PRINT;
}
