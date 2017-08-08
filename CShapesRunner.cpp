// TableCtors.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

#include <Utils/Stub.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Interface.hpp>
#include <Flyweight/Flyweight.hpp>
#include <Utils/UtilsForMT.hpp>

using namespace defaultVals;
using namespace communication;
using namespace assertWrapper;
using namespace funs;
using namespace typeLiterals;

#define STUB

int main(int argc, char **argv)
{
    {
        CFlyweight application(ZERO);
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

    //{
    //    CFlyweight application(TEN);
    //    std::vector<std::vector<std::string>> inCommands
    //    {
    //        { "go", "10" },
    //        { "createRect", "0", "1", "2" },
    //        { "createSquare", "1", "4" },
    //        { "createCircle", "2", "9" },
    //        { "createTriangle", "3", "3", "4", "5" },
    //        { "createTrapezoid", "4", "2", "3", "4", "5" }
    //    };

    //    for (auto command : inCommands)
    //    {
    //        application.interpretCommand(command);
    //    }

    //    application.printAll();

    //    bool ifWrongAreasCalculated = false;
    //    double sumOfAreas = application.sumAreas(ifWrongAreasCalculated);
    //    if (ifWrongAreasCalculated)
    //    {
    //        Logger()
    //            << SUM_OF_AREAS << SEPARATOR 
    //            << ERROR << SEPARATOR
    //            << SHAPE_CAN_NOT_EXIST
    //            << POST_PRINT;
    //    }
    //    else
    //    {
    //        Logger()
    //            << SUM_OF_AREAS << SEPARATOR
    //            << std::to_string(sumOfAreas)
    //            << POST_PRINT;
    //    }

        //bool ifWrongPerimetersCalculated = false;
        //double sumOfPerimeters = application.sumPerimeters(ifWrongPerimetersCalculated);
        //if (ifWrongPerimetersCalculated)
        //{
        //    Logger()
        //        << SUM_OF_PERIMETERS << SEPARATOR
        //        << ERROR << SEPARATOR
        //        << SHAPE_CAN_NOT_EXIST
        //        << POST_PRINT;
        //}
        //else
        //{
        //    Logger()
        //        << SUM_OF_PERIMETERS << SEPARATOR
        //        << std::to_string(sumOfPerimeters)
        //        << POST_PRINT;
        //}

    //    std::cout << std::endl << "Dzieki za uzycie programu, Korytko_MS" << POST_PRINT << POST_PRINT;
    //    system("Pause");
    //}

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


