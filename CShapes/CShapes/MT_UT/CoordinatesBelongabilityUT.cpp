#include "stdafx.h"
#include <gtest/gtest.h>

#include <limits>
#include <vector>

#include "../Shapes/Point.hpp"
#include "../Geometry/CoordinatesBelongability.h"
#include "../Utils.hpp"
#include "../Logger.h"

using namespace defaultVals;
using namespace geometry;
namespace
{
    class CCoordinatesBelongabilityTest : public testing::Test
    {
    protected:
        virtual void SetUp()
        {}

        virtual void TearDown()
        {}
    };

    TEST_F(CCoordinatesBelongabilityTest, Implicit_CTOR_True_True)
    {
        std::map<char, bool> belongabilityVals;
        belongabilityVals[X] = true;
        belongabilityVals[Y] = true;

        CCoordinatesBelongability belongability = belongabilityVals;

        ASSERT_TRUE(true);
    }

    TEST_F(CCoordinatesBelongabilityTest, Default_CTOR_False)
    {
        CCoordinatesBelongability belongability;

        ASSERT_FALSE(belongability);
    }

    TEST_F(CCoordinatesBelongabilityTest, operatorBool_True_True_Expect_True)
    {
        std::map<char, bool> belongabilityVals;
        belongabilityVals[X] = true;
        belongabilityVals[Y] = true;

        CCoordinatesBelongability belongability = belongabilityVals;

        ASSERT_TRUE(belongability);
    }

    TEST_F(CCoordinatesBelongabilityTest, operatorBool_False_True_Expect_False)
    {
        std::map<char, bool> belongabilityVals;
        belongabilityVals[X] = false;
        belongabilityVals[Y] = true;

        CCoordinatesBelongability belongability = belongabilityVals;

        ASSERT_FALSE(belongability);
    }

    TEST_F(CCoordinatesBelongabilityTest, operatorBool_True_False_Expect_False)
    {
        std::map<char, bool> belongabilityVals;
        belongabilityVals[X] = true;
        belongabilityVals[Y] = false;

        CCoordinatesBelongability belongability = belongabilityVals;

        ASSERT_FALSE(belongability);
    }

    TEST_F(CCoordinatesBelongabilityTest, operatorBool_False_False_Expect_False)
    {
        std::map<char, bool> belongabilityVals;
        belongabilityVals[X] = false;
        belongabilityVals[Y] = false;

        CCoordinatesBelongability belongability = belongabilityVals;

        ASSERT_FALSE(belongability);
    }


    TEST_F(CCoordinatesBelongabilityTest, setBelong_X_True_Expect_True_False)
    {
        CCoordinatesBelongability belongability;
        belongability[X] = true;

        ASSERT_TRUE(belongability[X]);
        ASSERT_FALSE(belongability);
    }

    TEST_F(CCoordinatesBelongabilityTest, setBelong_Y_True_Expect_True_False)
    {
        CCoordinatesBelongability belongability;
        belongability[Y] = true;

        ASSERT_TRUE(belongability[Y]);
        ASSERT_FALSE(belongability);
    }

}
