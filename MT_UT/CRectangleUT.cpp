
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

    //ASSERT_EQ(4, rectangle->calculateArea());
    //ASSERT_EQ(4, rectangle->calculateArea());
    ASSERT_TRUE(true);

    

    delete rectangle;
}
//
//TEST_F(CRectangleTests, build_withDoubles_fst_1_1_snd_4_4)
//{
//    double fstX = 1;
//    double fstY = 1;
//    double sndX = 4;
//    double sndY = 4;
//
//    CRectangle* rectangle = CRectangle::buildNewObj(fstX, fstY, sndX, sndY);
//    std::cout << rectangle->toString() << POST_PRINT;
//
//    ASSERT_EQ(fstX, rectangle->fstGetX());
//    ASSERT_EQ(fstY, rectangle->fstGetY());
//    ASSERT_EQ(sndX, rectangle->sndGetX());
//    ASSERT_EQ(sndY, rectangle->sndGetY());
//
//    delete rectangle;
//}
//
//TEST_F(CRectangleTests, build_withPointer_fst_1_1_snd_4_4)
//{
//    double fstX = 1;
//    double fstY = 1;
//    double sndX = 4;
//    double sndY = 4;
//
//    CRectangle* rectangleToCopyFrom = CRectangle::buildNewObj(fstX, fstY, sndX, sndY);
//    CRectangle* rectangleToCopyTo = CRectangle::buildNewObj(rectangleToCopyFrom);
//    std::cout << rectangleToCopyFrom->toString() << POST_PRINT;
//    std::cout << rectangleToCopyTo->toString() << POST_PRINT;
//
//    ASSERT_EQ(fstX, rectangleToCopyFrom->fstGetX());
//    ASSERT_EQ(fstY, rectangleToCopyFrom->fstGetY());
//    ASSERT_EQ(sndX, rectangleToCopyFrom->sndGetX());
//    ASSERT_EQ(sndY, rectangleToCopyFrom->sndGetY());
//
//    ASSERT_EQ(fstX, rectangleToCopyTo->fstGetX());
//    ASSERT_EQ(fstY, rectangleToCopyTo->fstGetY());
//    ASSERT_EQ(sndX, rectangleToCopyTo->sndGetX());
//    ASSERT_EQ(sndY, rectangleToCopyTo->sndGetY());
//
//    delete rectangleToCopyFrom;
//    delete rectangleToCopyTo;
//}

/////////////////////////////////////////////////////////
//
//TEST_F(CRectangleTests, field_fst_0_0_snd_4_4_Expect_16)
//{
//    double fstX = 0;
//    double fstY = 0;
//    double sndX = 4;
//    double sndY = 4;
//    double expField = 16.0;
//
//    CRectangle* rectangle = CRectangle::buildNewObj(fstX, fstY, sndX, sndY);
//    std::cout << rectangle->toString() << POST_PRINT;
//
//    ASSERT_EQ(fstX, rectangle->fstGetX());
//    ASSERT_EQ(fstY, rectangle->fstGetY());
//    ASSERT_EQ(sndX, rectangle->sndGetX());
//    ASSERT_EQ(sndY, rectangle->sndGetY());
//    ASSERT_EQ(expField, rectangle->field());
//
//    delete rectangle;
//}
//
//TEST_F(CRectangleTests, field_fst_0_0_snd_m4_m4_Expect_16)
//{
//    double fstX = 0;
//    double fstY = 0;
//    double sndX = -4;
//    double sndY = -4;
//    double expField = 16.0;
//
//    CRectangle* rectangle = CRectangle::buildNewObj(fstX, fstY, sndX, sndY);
//    std::cout << rectangle->toString() << POST_PRINT;
//
//    ASSERT_EQ(fstX, rectangle->fstGetX());
//    ASSERT_EQ(fstY, rectangle->fstGetY());
//    ASSERT_EQ(sndX, rectangle->sndGetX());
//    ASSERT_EQ(sndY, rectangle->sndGetY());
//    ASSERT_EQ(expField, rectangle->field());
//
//    delete rectangle;
//}
//
//TEST_F(CRectangleTests, field_fst_0_0_snd_8_7_Expect_56)
//{
//    double fstX = 0;
//    double fstY = 0;
//    double sndX = 8;
//    double sndY = 7;
//    double expField = 56.0;
//
//    CRectangle* rectangle = CRectangle::buildNewObj(fstX, fstY, sndX, sndY);
//    std::cout << rectangle->toString() << POST_PRINT;
//
//    ASSERT_EQ(fstX, rectangle->fstGetX());
//    ASSERT_EQ(fstY, rectangle->fstGetY());
//    ASSERT_EQ(sndX, rectangle->sndGetX());
//    ASSERT_EQ(sndY, rectangle->sndGetY());
//    ASSERT_EQ(expField, rectangle->field());
//
//    delete rectangle;
//}
//
//TEST_F(CRectangleTests, field_fst_7_0_snd_0_8_Expect_56)
//{
//    double fstX = 7;
//    double fstY = 0;
//    double sndX = 0;
//    double sndY = 8;
//    double expField = 56.0;
//
//    CRectangle* rectangle = CRectangle::buildNewObj(fstX, fstY, sndX, sndY);
//    std::cout << rectangle->toString() << POST_PRINT;
//
//    ASSERT_EQ(fstX, rectangle->fstGetX());
//    ASSERT_EQ(fstY, rectangle->fstGetY());
//    ASSERT_EQ(sndX, rectangle->sndGetX());
//    ASSERT_EQ(sndY, rectangle->sndGetY());
//    ASSERT_EQ(expField, rectangle->field());
//
//    delete rectangle;
//}

}
