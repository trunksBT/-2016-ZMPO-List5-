cmake_minimum_required (VERSION 2.6)
 
project (CShapes)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(googletest/googletest)
include_directories(googletest/googletest/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

if(MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

include_directories(.)

set(HANDLERS
    Handlers/IShapeHandler.cpp
    Handlers/IShapeHandler.hpp
    Handlers/IHandler.cpp
    Handlers/IHandler.hpp
	Handlers/GoHandler.cpp
    Handlers/GoHandler.hpp
    Handlers/CreateRectDoubleHandler.cpp
    Handlers/CreateRectDoubleHandler.hpp
    Handlers/AreaHandler.cpp
    Handlers/AreaHandler.hpp

	Handlers/PrintAllHandler.cpp
    Handlers/PrintAllHandler.hpp

    #Handlers/CreatePointCopyHandler.cpp
    #Handlers/CreatePointCopyHandler.hpp
    #Handlers/CreatePointHandler.cpp
    #Handlers/CreatePointHandler.hpp
    #Handlers/CreateRectCopyHandler.cpp
    #Handlers/CreateRectCopyHandler.hpp
    #Handlers/CreateRectDefaultHandler.cpp
    #Handlers/CreateRectDefaultHandler.hpp
    #Handlers/GetPointXHandler.cpp
    #Handlers/GetPointXHandler.hpp
    #Handlers/GetPointYHandler.cpp
    #Handlers/GetPointYHandler.hpp
    #Handlers/HelpHandler.cpp
    #Handlers/HelpHandler.hpp

    #Handlers/RemoveAllHandler.cpp
    #Handlers/RemoveAllHandler.hpp
    #Handlers/RemoveHandler.cpp
    #Handlers/RemoveHandler.hpp
    #Handlers/SetPointHandler.cpp
    #Handlers/SetPointHandler.hpp
    #Handlers/ShowRectHandler.cpp
    #Handlers/ShowRectHandler.hpp
)

set(SHAPES
    Shapes/Point.cpp
    Shapes/Point.hpp
    Shapes/Rectangle.cpp
    Shapes/Rectangle.hpp
    Shapes/Shape.cpp
    Shapes/Shape.hpp
)

set(UTILS
    Utils/Interface.cpp
    Utils/Interface.hpp
    Utils/Logger.cpp
    Utils/Logger.hpp
    Utils/Stub.cpp
    Utils/Stub.hpp
    Utils/Utils.cpp
    Utils/Utils.hpp
    Utils/UtilsForMT.cpp
    Utils/UtilsForMT.hpp
)

set(MT_UT
	MT_UT/CBridgesUT.cpp
    # MT_UT/CPointUT.cpp
    MT_UT/CRectangleUT.cpp
    # MT_UT/FlyweightProperAmountOfArgsButWrongMT.cpp
    # MT_UT/FlyweightProperArgsMT.cpp
    # MT_UT/FlyweightUnproperAmountOfArgsMT.cpp
    MT_UT/ParsingValuesUT.hpp
)

set(FLYWEIGHT
    Flyweight/Flyweight.cpp
    Flyweight/Flyweight.hpp
)

set(BRIDGES
	Bridges/BridgesModel.cpp
	Bridges/BridgesModel.hpp
	Bridges/IBridge.hpp
	Bridges/RectangleAreaBridge.cpp
	Bridges/RectangleAreaBridge.hpp
	Bridges/RectanglePerimeterBridge.cpp
	Bridges/RectanglePerimeterBridge.hpp
)

source_group("Handlers" FILES ${HANDLERS})
source_group("MT_UT" FILES ${MT_UT})
source_group("Shapes" FILES ${SHAPES})
source_group("Utils" FILES ${UTILS})
source_group("Flyweight" FILES ${FLYWEIGHT})
source_group("Bridges" FILES ${BRIDGES})

add_executable(${PROJECT_NAME} CShapesRunner.cpp
    ${HANDLERS}
    ${SHAPES}
    ${UTILS}
    ${MT_UT}
    ${FLYWEIGHT}
    ${BRIDGES}
)

add_dependencies(${PROJECT_NAME} gtest_main)
target_link_libraries(${PROJECT_NAME} gtest_main gtest)
