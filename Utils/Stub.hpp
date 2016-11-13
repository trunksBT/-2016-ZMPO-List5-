#pragma once

#include <vector>
#include <string>

namespace stub
{
extern std::vector<std::string> emptyCommand;
extern std::vector<std::string> noCommand;

extern std::vector<std::string> gom1m1;
extern std::vector<std::string> gom10;
extern std::vector<std::string> go0m1;
extern std::vector<std::string> go00;
extern std::vector<std::string> go10;
extern std::vector<std::string> go01;
extern std::vector<std::string> go66;
extern std::vector<std::string> go60;
extern std::vector<std::string> go06;

extern std::vector<std::string> createPoint1_1y5_5y5;
extern std::vector<std::string> createPoint6_1y5_5y5;
extern std::vector<std::string> createPoint0_m1y5_5y5;
extern std::vector<std::string> createPoint0_1y5_m5y5;

extern std::vector<std::string> setPoint1_1y5_5y5;
extern std::vector<std::string> setPoint6_1y5_5y5;
extern std::vector<std::string> setPoint0_m1y5_5y5;
extern std::vector<std::string> setPoint0_1y5_m5y5;

extern std::vector<std::string> createPointCopy00;
extern std::vector<std::string> createPointCopy10;
extern std::vector<std::string> createPointCopym1_0;
extern std::vector<std::string> createPointCopy0_m1;
extern std::vector<std::string> createPointCopym1_m1;
extern std::vector<std::string> createPointCopy10;
extern std::vector<std::string> createPointCopy60;

extern std::vector<std::string> getPointX0;
extern std::vector<std::string> getPointXm1;
extern std::vector<std::string> getPointX1;
extern std::vector<std::string> getPointX6;

extern std::vector<std::string> getPointY0;
extern std::vector<std::string> getPointYm1;
extern std::vector<std::string> getPointY1;
extern std::vector<std::string> getPointY6;

extern std::vector<std::string> createRectPoints1_1_1;
extern std::vector<std::string> createRectPoints1_0_1;
extern std::vector<std::string> createRectPoints6_0_1;
extern std::vector<std::string> createRectPoints0_m1_5;
extern std::vector<std::string> createRectPoints0_5_m1;

extern std::vector<std::string> createRectDouble1_1y5_5y5_1y5_5y5;
extern std::vector<std::string> createRectDouble1_1y5_5y5_m1_m1;
extern std::vector<std::string> createRectDouble1_m1_m1_1y5_5y5;
extern std::vector<std::string> createRectDouble6_1y5_5y5_1y5_5y5;
extern std::vector<std::string> createRectDouble0_m1_5_1y5_5y5;

extern std::vector<std::string> createRectCopy00;
extern std::vector<std::string> createRectCopy10;
extern std::vector<std::string> createRectCopym1_0;
extern std::vector<std::string> createRectCopy0_m1;
extern std::vector<std::string> createRectCopym1_m1;
extern std::vector<std::string> createRectCopy60;

extern std::vector<std::string> fieldRectX0;
extern std::vector<std::string> fieldRectXm1;
extern std::vector<std::string> fieldRectX1;
extern std::vector<std::string> fieldRectX6;

extern std::vector<std::string> showRect0;
extern std::vector<std::string> showRectm1;
extern std::vector<std::string> showRect6;
extern std::vector<std::string> showRect10;

extern std::vector<std::string> printAll;

extern std::vector<std::string> help;
}

namespace wrongAmountStub
{
extern std::vector<std::string> goToSmall;
extern std::vector<std::string> createToSmall;
extern std::vector<std::string> createDefToSmall;
extern std::vector<std::string> createCopy0ToSmall;
extern std::vector<std::string> printToSmall;
extern std::vector<std::string> deleteToSmall;
extern std::vector<std::string> getValue0ToSmall;
extern std::vector<std::string> setValue0_0ToSmall;
extern std::vector<std::string> wrongCommandToSmall;

extern std::vector<std::string> goToBig;
extern std::vector<std::string> createToBig;
extern std::vector<std::string> createDefToBig;
extern std::vector<std::string> createCopy0ToBig;
extern std::vector<std::string> printToBig;
extern std::vector<std::string> deleteToBig;
extern std::vector<std::string> deleteAllToBig;
extern std::vector<std::string> getValue0ToBig;
extern std::vector<std::string> setValue0_0ToBig;
extern std::vector<std::string> wrongCommandToBig;
}

namespace wrongTypeStub
{
extern std::vector<std::string> goZ;
extern std::vector<std::string> createZZZ;
extern std::vector<std::string> createDefZ;
extern std::vector<std::string> createCopyZZ;
extern std::vector<std::string> printZ;
extern std::vector<std::string> deleteZ;
extern std::vector<std::string> getValueZZ;
extern std::vector<std::string> setValue0ZZZ;
}
