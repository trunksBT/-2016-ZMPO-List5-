// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
#include <boost/any.hpp>

constexpr const char* AREA = "area";
constexpr const char* FLOAT_TYPE = "float";
constexpr const char* PERIMETER = "perimeter";

using myIM = std::map<const char*, boost::any>;

class IBridge;
using myBridges = std::map<const char*, IBridge*>;

class IBridge
{
public:
    virtual float perform(const myIM& inVal) = 0;
    virtual ~IBridge()
    {
        std::cout << "IBridge Dtor" << std::endl;
    }
};

class CircleAreaBridge : public IBridge
{
public:
    float perform(const myIM& inVal) override
    {
        std::cout << "CircleAreaBridge" << std::endl;

        if (inVal.count(FLOAT_TYPE))
        {
            return boost::any_cast<float>(inVal.at(FLOAT_TYPE));
        }
        else
        {
            return float();
        }

    }
    virtual ~CircleAreaBridge()
    {
        std::cout << "CircleAreaBridge Dtor" << std::endl;
    }
};

class IShape
{
public:
    myBridges bridges_;

    IShape(const myBridges& inBridges)
        : bridges_(inBridges)
    {
        std::cout << "IShape Ctor" << std::endl;
    };

    virtual float area() = 0;
    virtual float perimeter() = 0;

    virtual ~IShape()
    {
        std::cout << "IShape Dtor" << std::endl;

        for (auto it = bridges_.begin(); it != bridges_.end(); ++it)
        {
            delete it->second;
        }
    }
};

class Circle : public IShape
{
    float one_;
public:
    explicit Circle(float one, IBridge* fstBridge = new CircleAreaBridge(), IBridge* sndBridge = new CircleAreaBridge())
        : IShape({ { AREA, fstBridge }, { PERIMETER, sndBridge } }), one_(one)
    {
        std::cout << "Circle Ctor" << std::endl;
    }

    virtual float area()
    {
        return bridges_.at(AREA)->perform({ {FLOAT_TYPE, one_} });
    }

    virtual float perimeter()
    {
        return 0.0;
    }

    virtual ~Circle()
    {
        std::cout << "Circle Dtor" << std::endl;
    };
};

int main()
{
    IShape** someShapes = new IShape*[10];
    someShapes[0] = new Circle(3.0);

    for (int i = 0; i < 1; i++)
    {
        std::cout << someShapes[i]->area() << std::endl;
    }

    delete someShapes[0];
    delete[] someShapes;
    return 0;


    //std::cout << boost::any_cast<int>(anyVals[0]) + 5;


    //std::cout << boost::any_cast<std::string>(anyVals[1]);

    return 0;
}

