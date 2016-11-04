#pragma once
//
//#include "stdafx.h"
//#include "TempHeader.h"
//#include <iostream>
//#include <sstream>
//
//int main()
//{
//    std::stringstream maxDoubleValnStream;
//    maxDoubleValnStream << std::fixed << (std::numeric_limits<double>::max)();
//    std::string maxDoubleValue = maxDoubleValnStream.str();
//
//    std::stringstream maxDoubleValnStreamPlusOneVal;
//    maxDoubleValnStreamPlusOneVal << std::fixed << (std::numeric_limits<double>::max)();
//    maxDoubleValnStreamPlusOneVal << "0";
//    std::string maxDoubleValuePlusOneVal = maxDoubleValnStreamPlusOneVal.str();
//
//    std::stringstream minDoubleValStream;
//    minDoubleValStream << std::fixed << (std::numeric_limits<double>::lowest)();
//    std::string minDoubleValue = minDoubleValStream.str();
//
//    std::stringstream minDoubleValStreamPlusOneVal;
//    minDoubleValStreamPlusOneVal << std::fixed << (std::numeric_limits<double>::lowest)();
//    minDoubleValStreamPlusOneVal << "0";
//    std::string minDoubleValuePlusOneVal = minDoubleValStreamPlusOneVal.str();
//
//    std::string doubleMinus = "--";
//    std::string doubleMinusWithValueInt = "--1";
//    std::string doubleMinusWithValueDouble = "--1.0";
//    std::string dot = ".";
//    std::string doubleDot = "..";
//    std::string dotAndValue = ".1";
//    std::string valueAndDot = "1.";
//    std::string dotAndMinusValue = ".-1";
//    std::string doubleDotWithValue = "1.1.";
//    std::string doubleDotWithValue2 = "1.1.2323";
//    std::string properVal1 = "123123123123.2112";
//    std::string properVal2 = "12312222222222222222222223123123.2112";
//    std::string wrongString = "adasd";
//    std::string wrongStringWithDot = "1.asd";
//    std::string integer = "1";
//
//    std::cout << std::boolalpha;
//    std::cout << maxDoubleValue << ": " << isDouble(maxDoubleValue) << std::endl;
//    std::cout << maxDoubleValuePlusOneVal << ": " << isDouble(maxDoubleValuePlusOneVal) << std::endl;
//    std::cout << minDoubleValue << ": " << isDouble(minDoubleValue) << std::endl;
//    std::cout << minDoubleValuePlusOneVal << ": " << isDouble(minDoubleValuePlusOneVal) << std::endl;
//    std::cout << doubleMinus << ": " << isDouble(doubleMinus) << std::endl;
//    std::cout << doubleMinusWithValueInt << ": " << isDouble(doubleMinusWithValueInt) << std::endl;
//    std::cout << doubleMinusWithValueDouble << ": " << isDouble(doubleMinusWithValueDouble) << std::endl;
//    std::cout << dot << ": " << isDouble(dot) << std::endl;
//    std::cout << doubleDot << ": " << isDouble(doubleDot) << std::endl;
//    std::cout << valueAndDot << ": " << isDouble(valueAndDot) << std::endl;
//    std::cout << dotAndValue << ": " << isDouble(dotAndValue) << std::endl;
//    std::cout << dotAndMinusValue << ": " << isDouble(dotAndMinusValue) << std::endl;
//    std::cout << doubleDotWithValue << ": " << isDouble(doubleDotWithValue) << std::endl;
//    std::cout << doubleDotWithValue2 << ": " << isDouble(doubleDotWithValue2) << std::endl;
//    std::cout << properVal1 << ": " << isDouble(properVal1) << std::endl;
//    std::cout << properVal2 << ": " << isDouble(properVal2) << std::endl;
//    std::cout << wrongString << ": " << isDouble(wrongString) << std::endl;
//    std::cout << wrongStringWithDot << ": " << isDouble(wrongStringWithDot) << std::endl;
//    std::cout << integer << ": " << isDouble(integer) << std::endl;
//
//    double tempVal = std::stod("1.");
//    std::cout << tempVal << std::endl;
//
//    return 0;
//}