#include "stdafx.h"
#include <gtest/gtest.h>

#include <limits>
#include <vector>
#include <string>
#include <utility>

#include "Flyweight.h"
#include "Stub.hpp"
#include "UtilsForMT.h"

using namespace defaultVals;
using namespace assertWrapper;

namespace
{
class CFlyweightUnproperAmountOfArgsMT : public testing::Test
{
protected:
    virtual void SetUp()
    {
        rcVal = CODE::ERROR;
    }

    virtual void TearDown()
    {}
protected:
    CFlyweight application;
    CODE rcVal;
};
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, createDefToSmall_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::createDefToSmall)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, createDefToBig_OnEmptyCFlyweight_Expect_ERROR_DONE)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::createDefToBig)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, createCopy0ToSmall_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::createCopy0ToSmall)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, createCopy0ToBig_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::createCopy0ToBig)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, printToSmall_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::printToSmall)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, printToBig_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::printToBig)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, deleteToSmall_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::deleteToSmall)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, deleteToBig_OnEmptyCFlyweight_Expect_DONE)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::deleteToBig)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, deleteAllToBig_OnEmptyCFlyweight_Expect_DONE)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::deleteAllToBig)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, getValue0ToToSmall_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::getValue0ToSmall)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, getValue0ToToBig_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::getValue0ToBig)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, getValueToBig_1_23_3_4_5_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::getValueToBig_1_23_3_4_5)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, setValue0_0ToSmall_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::setValue0_0ToSmall)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, setValue0_0ToBig_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::setValue0_0ToBig)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, wrongCommandToSmall_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::wrongCommandToSmall)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, wrongCommandToBig_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::wrongCommandToBig)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, createToSmall_getValue_1_2_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::createToSmall),
//        application.interpretCommand(stub::getValue1_2),
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightUnproperAmountOfArgsMT, createToBig_getValue_1_2_Expect_DONE)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::createToBig),
//        application.interpretCommand(stub::getValue1_2),
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}

}

