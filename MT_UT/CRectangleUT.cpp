
#include <gtest/gtest.h>

#include <limits>
#include <vector>

#include <Shapes/Rectangle.hpp>
#include <Utils/Utils.hpp>

using namespace defaultVals;
namespace
{
class CRectangleTests : public testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}
};

TEST_F(CRectangleTests, build_width_1_height_4)
{
    double width = 1;
    double height = 4;

    CRectangle* rectangle = CRectangle::buildNewObj(width, height);
    std::cout << rectangle->toString() << POST_PRINT;

    ASSERT_TRUE(rectangle);
    delete rectangle;
}

TEST_F(CRectangleTests, build_default)
{
    CRectangle* rectangle = CRectangle::buildNewObj();
    std::cout << rectangle->toString() << POST_PRINT;

    ASSERT_TRUE(rectangle);
    delete rectangle;
}

TEST_F(CRectangleTests, build_copyCtor)
{
    CRectangle* rectangle = CRectangle::buildNewObj();
    CRectangle* afterClone = CRectangle::buildNewObj(rectangle);

    std::cout << rectangle->toString() << POST_PRINT;
    std::cout << afterClone->toString() << POST_PRINT;
   
    ASSERT_TRUE(rectangle);
    ASSERT_TRUE(afterClone);
    delete rectangle;
    delete afterClone;
}

TEST_F(CRectangleTests, build_calculateArea_and_Perimeter_defVals)
{
    CRectangle* rectangle = CRectangle::buildNewObj();

    std::cout << rectangle->toString() << POST_PRINT;

    ASSERT_EQ(0, rectangle->calculateArea());
    ASSERT_EQ(0, rectangle->calculatePerimeter());

    delete rectangle;
}

TEST_F(CRectangleTests, build_calculateArea_and_Perimeter_4y0_5y0)
{
    CRectangle* rectangle = CRectangle::buildNewObj(4.0, 5.0);

    std::cout << rectangle->toString() << POST_PRINT;

    ASSERT_EQ(20.0, rectangle->calculateArea());
    ASSERT_EQ(18.0, rectangle->calculatePerimeter());

    delete rectangle;
}

}
