#include "stdafx.h"
#include <gtest/gtest.h>
#include "Point.hpp"
#include "Utils.hpp"
#include <limits>
#include <vector>

using namespace defaultVals;
namespace
{
class CPointTests : public testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}
};

TEST_F(CPointTests, build_x_m1_y_m1_Expect_True)
{
    double inX = -1;
    double inY = -1;
    CPoint* inPoint = CPoint::buildNewObj(inX, inY);
    
    ASSERT_EQ(inX, inPoint->getX());
    ASSERT_EQ(inY, inPoint->getY());

    delete inPoint;
}

TEST_F(CPointTests, build_x_1_y_1_Expect_True)
{
    double inX = 1;
    double inY = 1;
    CPoint* inPoint = CPoint::buildNewObj(inX, inY);
    
    ASSERT_EQ(inX, inPoint->getX());
    ASSERT_EQ(inY, inPoint->getY());

    delete inPoint;
}

TEST_F(CPointTests, build_x_1_y_1_set_x_0_y_0_Expect_True)
{
    double inX = 1;
    double inY = 1;

    double newX = 0;
    double newY = 0;
    CPoint* inPoint = CPoint::buildNewObj(inX, inY);
    
    inPoint->setX(newX);
    inPoint->setY(newY);

    ASSERT_EQ(newX, inPoint->getX());
    ASSERT_EQ(newY, inPoint->getY());

    delete inPoint;
}

TEST_F(CPointTests, copyCtor_x_1_y_1_onEmptyPtr_Expect_True)
{
    double inX = 1;
    double inY = 1;

    CPoint* sourcePoint = CPoint::buildNewObj(inX, inY);
    CPoint* goalPoint = new CPoint(*sourcePoint);

    ASSERT_EQ(inX, goalPoint->getX());
    ASSERT_EQ(inY, goalPoint->getY());

    delete sourcePoint;
    delete goalPoint;
}

TEST_F(CPointTests, buildCopyCtor_x_1_y_1_onEmptyPtr_Expect_True)
{
    double inX = 1;
    double inY = 1;
    double inX2 = 2;
    double inY2 = 2;

    CPoint* sourcePoint = CPoint::buildNewObj(inX, inY);
    CPoint* goalPoint = CPoint::buildNewObj(sourcePoint);

    ASSERT_EQ(inX, goalPoint->getX());
    ASSERT_EQ(inY, goalPoint->getY());

    delete sourcePoint;
    delete goalPoint;
}

TEST_F(CPointTests, buildCopyCtor_x_1_y_1_onNotEmptyPtr_Expect_True)
{
    double inX = 1;
    double inY = 1;
    double inX2 = 2;
    double inY2 = 2;

    CPoint* sourcePoint = CPoint::buildNewObj(inX, inY);
    CPoint* goalPoint = CPoint::buildNewObj(inX2, inY2);
    delete goalPoint;
    goalPoint = CPoint::buildNewObj(sourcePoint);;


    ASSERT_EQ(inX, goalPoint->getX());
    ASSERT_EQ(inY, goalPoint->getY());

    delete sourcePoint;
    delete goalPoint;
}

}
