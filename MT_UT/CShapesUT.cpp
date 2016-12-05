
#include <gtest/gtest.h>

#include <limits>
#include <vector>

#include <Shapes/Rectangle.hpp>
#include <Shapes/Square.hpp>
#include <Utils/Utils.hpp>

using namespace defaultVals;
namespace
{
class CShapesUT : public testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}
};

TEST_F(CShapesUT, Rectangle_build_width_1_height_4)
{
    double width = 1;
    double height = 4;

    CShape* rectangle = CRectangle::buildNewObj(width, height);
    std::cout << rectangle->toString() << POST_PRINT;

    ASSERT_TRUE(rectangle);
    delete rectangle;
}

TEST_F(CShapesUT, Rectangle_build_default)
{
    CShape* rectangle = CRectangle::buildNewObj();
    std::cout << rectangle->toString() << POST_PRINT;

    ASSERT_TRUE(rectangle);
    delete rectangle;
}

TEST_F(CShapesUT, Rectangle_build_copyCtor)
{
    CShape* rectangle = CRectangle::buildNewObj();
    CShape* afterClone = CRectangle::buildNewObj(
        dynamic_cast<CRectangle*>(rectangle));

    std::cout << rectangle->toString() << POST_PRINT;
    std::cout << afterClone->toString() << POST_PRINT;
   
    ASSERT_TRUE(rectangle);
    ASSERT_TRUE(afterClone);
    delete rectangle;
    delete afterClone;
}

TEST_F(CShapesUT, Rectangle_build_calculateArea_and_Perimeter_defVals)
{
    CShape* rectangle = CRectangle::buildNewObj();

    std::cout << rectangle->toString() << POST_PRINT;

    ASSERT_EQ(0, rectangle->calculateArea());
    ASSERT_EQ(0, rectangle->calculatePerimeter());

    delete rectangle;
}

TEST_F(CShapesUT, Rectangle_build_calculateArea_and_Perimeter_4y0_5y0)
{
    CShape* rectangle = CRectangle::buildNewObj(4.0, 5.0);

    std::cout << rectangle->toString() << POST_PRINT;

    ASSERT_EQ(20.0, rectangle->calculateArea());
    ASSERT_EQ(18.0, rectangle->calculatePerimeter());

    delete rectangle;
}


TEST_F(CShapesUT, Square_build_width_1)
{
    double width = 1;
    double height = 4;

    CShape* square = CSquare::buildNewObj(width);
    std::cout << square->toString() << POST_PRINT;

    ASSERT_TRUE(square);
    delete square;
}

TEST_F(CShapesUT, Square_build_default)
{
    CShape* square = CSquare::buildNewObj();
    std::cout << square->toString() << POST_PRINT;

    ASSERT_TRUE(square);
    delete square;
}

TEST_F(CShapesUT, Square_build_copyCtor)
{
    CShape* square = CSquare::buildNewObj();
    CShape* afterClone = CSquare::buildNewObj(
        dynamic_cast<CSquare*>(square));

    std::cout << square->toString() << POST_PRINT;
    std::cout << afterClone->toString() << POST_PRINT;

    ASSERT_TRUE(square);
    ASSERT_TRUE(afterClone);
    delete square;
    delete afterClone;
}

TEST_F(CShapesUT, Square_build_calculateArea_and_Perimeter_defVals)
{
    CShape* square = CSquare::buildNewObj();

    std::cout << square->toString() << POST_PRINT;

    ASSERT_EQ(0, square->calculateArea());
    ASSERT_EQ(0, square->calculatePerimeter());

    delete square;
}

TEST_F(CShapesUT, Square_build_calculateArea_and_Perimeter_5y0)
{
    CShape* square = CSquare::buildNewObj(5.0);

    std::cout << square->toString() << POST_PRINT;

    ASSERT_EQ(25.0, square->calculateArea());
    ASSERT_EQ(20.0, square->calculatePerimeter());

    delete square;
}


}
