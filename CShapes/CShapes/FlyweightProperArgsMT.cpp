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
using namespace funs;

namespace
{
class CFlyweightProperArgsMT : public testing::Test
{
protected:
    virtual void SetUp()
    {
        rcVal = CODE::ERROR;
    }

    virtual void TearDown()
    {
        application.releaseResources();
    }
protected:
    CFlyweight application;
    CODE rcVal;
};

TEST_F(CFlyweightProperArgsMT, gom1m1_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::gom1m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, gom10_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::gom10)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go0m1_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go0m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go00_OnEmptyCFlyweight)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go00)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go10_OnEmptyCFlyweight)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go10)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go01_OnEmptyCFlyweight)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go01)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go66_OnEmptyCFlyweight)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go60_OnEmptyCFlyweight)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go60)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go06_OnEmptyCFlyweight)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go06)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createPoint1_1y5_5y5)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPoint1_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createPoint6_1y5_5y5)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPoint6_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createPoint0_m1y5_5y5)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPoint0_m1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createPoint0_1y5_m5y5)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPoint0_1y5_m5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, setPoint1_1y5_5y5)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::setPoint1_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, setPoint6_1y5_5y5)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::setPoint6_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, setPoint0_m1y5_5y5)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::setPoint0_m1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, setPoint0_1y5_m5y5)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::setPoint0_1y5_m5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

////////////////////////////////////////////////

TEST_F(CFlyweightProperArgsMT, createPointCopy00)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPointCopy00)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createPointCopy10)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPointCopy10)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createPointCopym1_0)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPointCopym1_0)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createPointCopy0_m1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPointCopy0_m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createPointCopym1_m1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPointCopym1_m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createPointCopy60)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createPointCopy60)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

/////////////////////////////////////////

TEST_F(CFlyweightProperArgsMT, getPointX0)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::getPointX0)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, getPointXm1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::getPointXm1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, getPointX1)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::getPointX1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, getPointX6)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::getPointX6)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

/////////////////////////////////////////

TEST_F(CFlyweightProperArgsMT, getPointY0)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::getPointY0)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, getPointYm1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::getPointYm1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, getPointY1)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::getPointY1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, getPointY6)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::getPointY6)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

////////////////////////////////////////////////

TEST_F(CFlyweightProperArgsMT, createRectPoints1_1_1)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectPoints1_1_1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectPoints1_0_1)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectPoints1_0_1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectPoints6_0_1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectPoints6_0_1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectPoints0_m1_5)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectPoints0_m1_5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectPoints0_5_m1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectPoints0_5_m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

////////////////////////////////////////////


TEST_F(CFlyweightProperArgsMT, createRectDouble1_1y5_5y5_1y5_5y5)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectDouble1_1y5_5y5_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectDouble1_1y5_5y5_m1_m1)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectDouble1_1y5_5y5_m1_m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectDouble1_m1_m1_1y5_5y5)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectDouble1_m1_m1_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectDouble6_1y5_5y5_1y5_5y5)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectDouble6_1y5_5y5_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectDouble0_m1_5_1y5_5y5)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectDouble0_m1_5_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

//////////////////////////////////////////////////////////////////


TEST_F(CFlyweightProperArgsMT, createRectCopy00)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectCopy00)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectCopy10)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectCopy10)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectCopym1_0)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectCopym1_0)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectCopy0_m1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectCopy0_m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectCopym1_m1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectCopym1_m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, createRectCopy60)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::createRectCopy60)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

///////////////////////////////////////////////////

TEST_F(CFlyweightProperArgsMT, fieldRectX0)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::fieldRectX0)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, fieldRectXm1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::fieldRectXm1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, fieldRectX1)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::fieldRectX1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, fieldRectX6)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::fieldRectX6)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, bigPoints_fieldRect)
{
    std::vector<std::string> setBigPoint1 =
    { 
        "setPoint", "0", 
        "0.0",
        "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0"
    };

    std::vector<std::string> setBigPoint2 =
    {
        "setPoint", "1",
        "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0",
        "0.0"
    };

    std::vector<std::string> createRectPoints0_0_0 = 
    { 
        "createRectPoints", "0", "0", "1" 
    };

    std::vector<std::string> printAll =
    {
        "printAll"
    };

    std::vector<std::string> fieldRectTest =
    {
        "fieldRect", "0"
    };


    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(setBigPoint1),
        application.interpretCommand(printAll),
        application.interpretCommand(setBigPoint2),
        application.interpretCommand(printAll),
        application.interpretCommand(createRectPoints0_0_0),
        application.interpretCommand(printAll),
        application.interpretCommand(fieldRectTest)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, showRect0)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::showRect0)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, showRectm1)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::showRectm1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, showRect6)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::showRect6)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}


TEST_F(CFlyweightProperArgsMT, showRect10)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::showRect10)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, printAll)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::printAll)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}


}
