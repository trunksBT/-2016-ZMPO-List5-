// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

#include "Stub.hpp"
#include "Utils.hpp"
#include "Interface.hpp"
#include "Flyweight.h"
#include "UtilsForMT.h"

using namespace defaultVals;
using namespace communication;
using namespace assertWrapper;
using namespace funs;

#define STUB

int main(int argc, char **argv)
{
    {
        CFlyweight application(ZERO, ZERO);
        CODE commandResult = CODE::ERROR;

        std::cout << "Pass command" << std::endl;
        do
        {
            auto command = receiveAndLexCommandFromUser();
            commandResult = application.interpretCommand(command);
            std::cout << toString(commandResult) << POST_PRINT;
        } while (commandResult != CODE::CLOSE);

        std::cout << std::endl << "Dzieki za uzycie programu, Korytko_MS" << POST_PRINT << POST_PRINT;
        system("Pause");
    }
   
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


