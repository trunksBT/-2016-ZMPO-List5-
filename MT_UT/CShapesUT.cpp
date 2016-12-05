
#include <gtest/gtest.h>

#include <limits>
#include <vector>

#include <Shapes/Rectangle.hpp>
#include <Shapes/Square.hpp>
#include <Shapes/Triangle.hpp>
#include <Shapes/Circle.hpp>

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
    CShape* rectangle = CRectangle::buildNewObj(
        BridgesModel({ { AREA, new CRectanglePerimeterBridge() },{ PERIMETER, new CRectanglePerimeterBridge() } }));
    CShape* afterClone = CRectangle::buildNewObj(
        dynamic_cast<CRectangle*>(rectangle));

    std::cout << rectangle->calculateArea() << POST_PRINT;
    std::cout << afterClone->calculateArea() << POST_PRINT;
   
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
    double radious = 1;

    CShape* square = CSquare::buildNewObj(radious);
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

TEST_F(CShapesUT, Triangle_build_side_Egiptian)
{
    double side1 = 3;
    double side2 = 4;
    double side3 = 5;

    CShape* square = CTriangle::buildNewObj(side1, side2, side3);
    std::cout << square->toString() << POST_PRINT;

    ASSERT_TRUE(square);
    delete square;
}

TEST_F(CShapesUT, Triangle_build_default)
{
    CShape* square = CTriangle::buildNewObj();
    std::cout << square->toString() << POST_PRINT;

    ASSERT_TRUE(square);
    delete square;
}

TEST_F(CShapesUT, Triangle_build_copyCtor)
{
    CShape* square = CTriangle::buildNewObj();

    CShape* afterClone = CTriangle::buildNewObj(
        dynamic_cast<CTriangle*>(square));

    std::cout << square->toString() << POST_PRINT;
    std::cout << afterClone->toString() << POST_PRINT;

    ASSERT_TRUE(square);
    ASSERT_TRUE(afterClone);
    delete square;
    delete afterClone;
}

TEST_F(CShapesUT, Triangle_build_calculateArea_and_Perimeter_defVals)
{
    CShape* square = CTriangle::buildNewObj();

    std::cout << square->toString() << POST_PRINT;

    ASSERT_EQ(0, square->calculateArea());
    ASSERT_EQ(0, square->calculatePerimeter());

    delete square;
}

TEST_F(CShapesUT, Triangle_build_calculateArea_and_Perimeter_Egiptian)
{
    double side1 = 3;
    double side2 = 4;
    double side3 = 5;

    CShape* square = CTriangle::buildNewObj(side1, side2, side3);

    std::cout << square->toString() << POST_PRINT;

    ASSERT_EQ(6, static_cast<int>(square->calculateArea()));
    ASSERT_EQ(12, static_cast<int>(square->calculatePerimeter()));

    delete square;
}

TEST_F(CShapesUT, Triangle_build_calculateArea_and_Perimeter_Wrong)
{
    double side1 = 1;
    double side2 = 2;
    double side3 = 5;

    CShape* square = CTriangle::buildNewObj(side1, side2, side3);

    std::cout << square->toString() << POST_PRINT;

    ASSERT_TRUE(square);
    delete square;
}

}
