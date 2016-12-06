
#include <gtest/gtest.h>

#include <limits>
#include <vector>

#include <Shapes/Rectangle.hpp>
#include <Shapes/Square.hpp>
#include <Shapes/Triangle.hpp>
#include <Shapes/Circle.hpp>
#include <Shapes/Trapezoid.hpp>

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

    if (rectangle->isPossibleToCreate())
    {
        ASSERT_EQ(0, rectangle->calculateArea());
        ASSERT_EQ(0, rectangle->calculatePerimeter());
    }

    delete rectangle;
}

TEST_F(CShapesUT, Rectangle_build_calculateArea_and_Perimeter_4y0_5y0)
{
    CShape* rectangle = CRectangle::buildNewObj(4.0, 5.0);

    std::cout << rectangle->toString() << POST_PRINT;

    if (rectangle->isPossibleToCreate())
    {
        ASSERT_EQ(20.0, rectangle->calculateArea());
        ASSERT_EQ(18.0, rectangle->calculatePerimeter());
    }

    delete rectangle;
}
//
///////////////////////////////////////////////////////////////////

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

    if (square->isPossibleToCreate())
    {
        ASSERT_EQ(0, square->calculateArea());
        ASSERT_EQ(0, square->calculatePerimeter());
    }

    delete square;
}

TEST_F(CShapesUT, Square_build_calculateArea_and_Perimeter_5y0)
{
    CShape* square = CSquare::buildNewObj(5.0);

    std::cout << square->toString() << POST_PRINT;

    if (square->isPossibleToCreate())
    {
        ASSERT_EQ(25.0, square->calculateArea());
        ASSERT_EQ(20.0, square->calculatePerimeter());
    }

    delete square;
}
//
///////////////////////////////////////////////////////////////////
//
TEST_F(CShapesUT, Triangle_build_side_Egiptian)
{
    double side1 = 3;
    double side2 = 4;
    double side3 = 5;

    CShape* triangle = CTriangle::buildNewObj(side1, side2, side3);
    std::cout << triangle->toString() << POST_PRINT;

    ASSERT_TRUE(triangle);
    delete triangle;
}

TEST_F(CShapesUT, Triangle_build_default)
{
    CShape* triangle = CTriangle::buildNewObj();
    std::cout << triangle->toString() << POST_PRINT;

    ASSERT_TRUE(triangle);
    delete triangle;
}

TEST_F(CShapesUT, Triangle_build_copyCtor)
{
    CShape* triangle = CTriangle::buildNewObj();

    CShape* afterClone = CTriangle::buildNewObj(
        dynamic_cast<CTriangle*>(triangle));

    std::cout << triangle->toString() << POST_PRINT;
    std::cout << afterClone->toString() << POST_PRINT;

    ASSERT_TRUE(triangle);
    ASSERT_TRUE(afterClone);
    delete triangle;
    delete afterClone;
}
//
TEST_F(CShapesUT, Triangle_build_calculateArea_and_Perimeter_defVals)
{
    CShape* triangle = CTriangle::buildNewObj();

    std::cout << triangle->toString() << POST_PRINT;

    if (triangle->isPossibleToCreate())
    {
        ASSERT_EQ(0, triangle->calculateArea());
        ASSERT_EQ(0, triangle->calculatePerimeter());
    }

    delete triangle;
}

TEST_F(CShapesUT, Triangle_build_calculateArea_and_Perimeter_Egiptian)
{
    double side1 = 3;
    double side2 = 4;
    double side3 = 5;

    CShape* triangle = CTriangle::buildNewObj(side1, side2, side3);

    std::cout << triangle->toString() << POST_PRINT;

    if (triangle->isPossibleToCreate())
    {
        ASSERT_EQ(6, static_cast<int>(triangle->calculateArea()));
        ASSERT_EQ(12, static_cast<int>(triangle->calculatePerimeter()));
    }

    delete triangle;
}

TEST_F(CShapesUT, Triangle_build_calculateArea_and_Perimeter_Wrong)
{
    double side1 = 1;
    double side2 = 2;
    double side3 = 5;

    CShape* triangle = CTriangle::buildNewObj(side1, side2, side3);

    std::cout << triangle->toString() << POST_PRINT;

    ASSERT_TRUE(triangle);
    delete triangle;
}
//
/////////////////////////////////////////////////////////////////////
//
TEST_F(CShapesUT, Circle_build_Param_FromInternet)
{
    double radious = 9;

    CShape* circle = CCircle::buildNewObj(radious);
    std::cout << circle->toString() << POST_PRINT;

    ASSERT_TRUE(circle);
    delete circle;
}

TEST_F(CShapesUT, Circle_build_default)
{
    CShape* circle = CCircle::buildNewObj();
    std::cout << circle->toString() << POST_PRINT;

    ASSERT_TRUE(circle);
    delete circle;
}

TEST_F(CShapesUT, Circle_build_copyCtor)
{
    double radious = 9;

    CShape* circle = CCircle::buildNewObj(radious);
    CShape* afterClone = CCircle::buildNewObj(
        dynamic_cast<CCircle*>(circle));

    std::cout << circle->toString() << POST_PRINT;
    std::cout << afterClone->toString() << POST_PRINT;

    ASSERT_TRUE(circle);
    ASSERT_TRUE(afterClone);
    delete circle;
    delete afterClone;
}

TEST_F(CShapesUT, Circle_build_calculateArea_and_Perimeter_defVals)
{
    CShape* circle = CCircle::buildNewObj();

    std::cout << circle->toString() << POST_PRINT;

    if (circle->isPossibleToCreate())
    {
        ASSERT_EQ(0, circle->calculateArea());
        ASSERT_EQ(0, circle->calculatePerimeter());
    }

    delete circle;
}

TEST_F(CShapesUT, Circle_build_calculateArea_and_Perimeter_Egiptian)
{
    double radious = 9;

    CShape* circle = CCircle::buildNewObj(radious);

    std::cout << circle->toString() << POST_PRINT;

    if (circle->isPossibleToCreate())
    {
        ASSERT_EQ(254, static_cast<int>(circle->calculateArea()));
        ASSERT_EQ(56, static_cast<int>(circle->calculatePerimeter()));
    }

    delete circle;
}
//
///////////////////////////////////////////////////////////////////
//
TEST_F(CShapesUT, Trapezoid_build_Param_FromInternet)
{
    double side1 = 16;
    double side2 = 44;
    double leg1 = 17;
    double leg2 = 25;

    CShape* trapezoid = CTrapezoid::buildNewObj(side1, side2,
        leg1, leg2);
    std::cout << trapezoid->toString() << POST_PRINT;

    ASSERT_TRUE(trapezoid);
    delete trapezoid;
}

TEST_F(CShapesUT, Trapezoid_build_default)
{
    CShape* trapezoid = CTrapezoid::buildNewObj();
    std::cout << trapezoid->toString() << POST_PRINT;

    ASSERT_TRUE(trapezoid);
    delete trapezoid;
}

TEST_F(CShapesUT, Trapezoid_build_copyCtor)
{
    double side1 = 16;
    double side2 = 44;
    double leg1 = 17;
    double leg2 = 25;

    CShape* trapezoid = CTrapezoid::buildNewObj(side1, side2,
        leg1, leg2);
    CShape* afterClone = CTrapezoid::buildNewObj(
        dynamic_cast<CTrapezoid*>(trapezoid));

    std::cout << trapezoid->toString() << POST_PRINT;
    std::cout << afterClone->toString() << POST_PRINT;

    ASSERT_TRUE(trapezoid);
    ASSERT_TRUE(afterClone);
    delete trapezoid;
    delete afterClone;
}

TEST_F(CShapesUT, Trapezoid_build_calculateArea_and_Perimeter_defVals)
{
    CShape* trapezoid = CTrapezoid::buildNewObj();

    std::cout << trapezoid->toString() << POST_PRINT;

    if (trapezoid->isPossibleToCreate())
    {
        ASSERT_EQ(0, trapezoid->calculateArea());
        ASSERT_EQ(0, trapezoid->calculatePerimeter());
    }

    ASSERT_FALSE(false);

    delete trapezoid;
}

TEST_F(CShapesUT, Trapezoid_build_calculateArea_and_Perimeter_Egiptian)
{
    double side1 = 16;
    double side2 = 44;
    double leg1 = 17;
    double leg2 = 25;

    CShape* trapezoid = CTrapezoid::buildNewObj(side1, side2,
        leg1, leg2);

    std::cout << trapezoid->toString() << POST_PRINT;

    if (trapezoid->isPossibleToCreate())
    {
        ASSERT_EQ(102, static_cast<int>(trapezoid->calculatePerimeter()));
        ASSERT_EQ(450, static_cast<int>(trapezoid->calculateArea()));
    }

    delete trapezoid;
}

TEST_F(CShapesUT, Trapezoid_build_calculateArea_and_Perimeter_AsSquare)
{
    double side1 = 4;
    double side2 = 4;
    double leg1 = 4;
    double leg2 = 4;

    CShape* trapezoid = CTrapezoid::buildNewObj(side1, side2,
        leg1, leg2);

    std::cout << trapezoid->toString() << POST_PRINT;

    if (trapezoid->isPossibleToCreate())
    {
        ASSERT_EQ(16, static_cast<int>(trapezoid->calculateArea()));
        ASSERT_EQ(16, static_cast<int>(trapezoid->calculatePerimeter()));
    }

    delete trapezoid;
}

TEST_F(CShapesUT, Trapezoid_build_calculateArea_and_Perimeter_AsRectangle_1)
{
    double side1 = 4;
    double side2 = 6;
    double leg1 = 4;
    double leg2 = 6;

    CShape* trapezoid = CTrapezoid::buildNewObj(side1, side2,
        leg1, leg2);

    std::cout << trapezoid->toString() << POST_PRINT;

    if (trapezoid->isPossibleToCreate())
    {
        ASSERT_EQ(24, static_cast<int>(trapezoid->calculateArea()));
        ASSERT_EQ(20, static_cast<int>(trapezoid->calculatePerimeter()));
    }

    delete trapezoid;
}

TEST_F(CShapesUT, Trapezoid_build_calculateArea_and_Perimeter_Minus)
{
    double side1 = -1;
    double side2 = 6;
    double leg1 = 4;
    double leg2 = 6;

    CShape* trapezoid = CTrapezoid::buildNewObj(side1, side2,
        leg1, leg2);

    std::cout << trapezoid->toString() << POST_PRINT;

    if (trapezoid->isPossibleToCreate())
    {
        ASSERT_EQ(24, static_cast<int>(trapezoid->calculateArea()));
        ASSERT_EQ(20, static_cast<int>(trapezoid->calculatePerimeter()));
    }

    delete trapezoid;
}

TEST_F(CShapesUT, Trapezoid_build_calculateArea_and_Perimeter_AsRectangle_2)
{
    double side1 = 4;
    double side2 = 6;
    double leg1 = 6;
    double leg2 = 4;

    CShape* trapezoid = CTrapezoid::buildNewObj(side1, side2,
        leg1, leg2);

    std::cout << trapezoid->toString() << POST_PRINT;

    if (trapezoid->isPossibleToCreate())
    {
        ASSERT_EQ(24, static_cast<int>(trapezoid->calculateArea()));
        ASSERT_EQ(20, static_cast<int>(trapezoid->calculatePerimeter()));
    }

    delete trapezoid;
}

}
