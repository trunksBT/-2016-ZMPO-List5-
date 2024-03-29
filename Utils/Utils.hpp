#pragma once

#include <vector>
#include <exception>
#include <Shapes/Point.hpp>
#include <Shapes/Shape.hpp>
#include <limits>
#include <tuple>
#include <map>

enum class CODE : int
{
    DONE = 0,
    ERROR = 1,
    NOT_INITIALIZED = 2,
    CLOSE = 10
};

bool double_equals(double a, double b, double epsilon = 0.001);

namespace geometry
{
    constexpr char X = 'x';
    constexpr char Y = 'y';
}

namespace dataBusKeys
{
    namespace circle
    {
        constexpr const char* SIDE_SND = "radious";
    }

    namespace rectangle
    {
        constexpr const char* SIDE_FST = "sideFst";
        constexpr const char* SIDE_SND = "sideSnd";
    }

    namespace triangle
    {
        constexpr const char* SIDE_FST = "sideFst";
        constexpr const char* SIDE_SND = "sideSnd";
        constexpr const char* SIDE_THRD = "sideThrd";
    }

    namespace trapezoid
    {
        constexpr const char* SIDE_FST = "sideFst";
        constexpr const char* SIDE_SND = "sideSnd";
        constexpr const char* LEG_FST = "legFst";
        constexpr const char* LEG_SND = "legSnd";
        constexpr const char* HEIGHT = "height";
    }

    namespace square
    {
        constexpr const char* SIDE = "side";
    }

    namespace circle
    {
        constexpr const char* RADIOUS = "radious";
    }
}

namespace bridgeModelKeys
{
    namespace rectangle
    {
        constexpr const char* AREA = "rectangleArea";
        constexpr const char* PERIMETER = "rectanglePerimeter";
    }

    namespace square
    {
        constexpr const char* AREA = "squareArea";
        constexpr const char* PERIMETER = "squarePerimeter";
    }

    namespace triangle
    {
        constexpr const char* AREA = "triangleArea";
        constexpr const char* PERIMETER = "trianglePerimeter";
    }

    namespace trapezoid
    {
        constexpr const char* AREA = "trapezoidArea";
        constexpr const char* PERIMETER = "trapezoidPerimeter";
    }

    namespace circle
    {
        constexpr const char* AREA = "circleArea";
        constexpr const char* PERIMETER = "circlePerimeter";
    }
}

namespace typeLiterals
{
    constexpr const char* BRIDGES_MODEL = "BRIDGES_MODEL";
    constexpr const char* DOUBLE_OVERFLOW_OR_UNDERFLOW
        = "DOUBLE_OVERFLOW_OR_UNDERFLOW";
    constexpr const char* IBRIDGE = "IBRIDGE";

    constexpr const char* RECTANGLE_AREA_BRIDGE = "RECTANGLE_AREA_BRIDGE";
    constexpr const char* RECTANGLE_PERIMETER_BRIDGE = "RECTANGLE_PERIMETER_BRIDGE";

    constexpr const char* TRIANGLE_AREA_BRIDGE = "TRIANGLE_AREA_BRIDGE";
    constexpr const char* TRIANGLE_PERIMETER_BRIDGE = "TRIANGLE_PERIMETER_BRIDGE";

    constexpr const char* CIRCLE_AREA_BRIDGE = "CIRCLE_AREA_BRIDGE";
    constexpr const char* CIRCLE_PERIMETER_BRIDGE = "CIRCLE_PERIMETER_BRIDGE";

    constexpr const char* TRAPEZOID_AREA_BRIDGE = "TRAPEZOID_AREA_BRIDGE";
    constexpr const char* TRAPEZOID_PERIMETER_BRIDGE = "TRAPEZOID_PERIMETER_BRIDGE";

    constexpr const char* POINT = "CPOINT";
    constexpr const char* RECTANGLE = "CRECTANGLE";
    constexpr const char* SQUARE = "CSQUARE";
    constexpr const char* CIRCLE = "CCIRCLE";
    constexpr const char* TRIANGLE = "CTRIANGLE";
    constexpr const char* SHAPE = "SHAPE";
    constexpr const char* RADIOUS = "CRADIOUS";
    constexpr const char* TRAPEZOID = "CTRAPEZOID";


    constexpr const char* POINTS = "POINTS";
    constexpr const char* SHAPES = "SHAPES";

    constexpr const char* AREA_HANDLER = "AREA_HANDLER";
    constexpr const char* PERIMETER_HANDLER = "PERIMETER_HANDLER";
   
    constexpr const char* X = "X";
    constexpr const char* Y = "Y";
    constexpr const char* WIDTH = "WIDTH";
    constexpr const char* SIDE = "SIDE";
    constexpr const char* HEIGHT = "HEIGHT";
    constexpr const char* LEG = "LEG";
    constexpr const char* SUM_OF_AREAS = "SUM_OF_AREAS";
    constexpr const char* SUM_OF_PERIMETERS = "SUM_OF_PERIMETERS";
}

namespace defaultVals
{
    constexpr const char* CURSOR_SIGN = "! ";
    constexpr const char* OR = " || ";
    constexpr const char* PRE_PRINT = "   ";
    constexpr const char* POST_PRINT = "\n";
    constexpr const char* SEPARATOR = ": ";
    constexpr const char* BRACKET_OPEN = "( ";
    constexpr const char* BRACKET_CLOSE = " )";
    constexpr const char* LEN = "len";
    constexpr const char* VALUES = "values";
    constexpr const char* SPACE = " ";
    constexpr const char* COMMA_SPACE = ", ";
    constexpr const char* DEFAULT_TABLE_NAME = "KORYTKO_TABLE";

    constexpr const char* POST_COPIED_NAME = "_copy";
    constexpr const char* DTOR_PRE_PRINT = "DTOR: ";
    constexpr const char* CTOR_COPY_PRE_PRINT = "kopiuj: ";
    constexpr const char* CTOR_DEFAULT_PRE_PRINT = "bezp: ";
    constexpr const char* CTOR_DEFAULT_MOVE_PRINT = "przenoszenie: ";
    constexpr const char* CTOR_ARG1_PRE_PRINT = "parametr: ";
    constexpr const char* CTOR_DEF_PRE_PRINT = "default: ";
    constexpr const int INITIAL_FLYWEIGHT_CACHE_SIZE = 5;
    constexpr const int ZERO = 0;
    constexpr const int MINUS_ONE = -1;
    constexpr const int ONE = 1;
    constexpr const int TWO = 2;
    constexpr const int THREE = 3;
    constexpr const int FOUR = 4;
    constexpr const int FIVE = 5;
    constexpr const int TEN = 10;
    constexpr const long MAX_INT_VAL = (std::numeric_limits<int>::max)();
    constexpr const char* ERRORED_COMMAND_IDX = "Errored command idx";
    constexpr const char* POSSIBLE_LOSS_OF_DATA = "possible loss of data";
    constexpr const char INT_TYPE = 'i';
    constexpr const char DOUBLE_TYPE = 'd';
    constexpr const char STRING_TYPE = 's';
    constexpr const int DEFAULT_TABLE_VAL = -1;

    constexpr const double DEFAULT_FST_AXIS_VAL = 0.0;
    constexpr const double DEFAULT_SND_AXIS_VAL = 2.0;
    constexpr const int DEFAULT_FLYWEIGHT_CACHE_SIZE = FIVE;

    constexpr const int DOT_SIZE = 1;
    constexpr const int MINUS_SIZE = 1;
    constexpr const int MAX_SIZE_AFTER_DOT = 6;
    constexpr const int MAX_SIZE_BEFORE_DOT = 309;
    constexpr const int MAX_SIZE_OF_DOUBLE = MAX_SIZE_BEFORE_DOT + DOT_SIZE + MAX_SIZE_AFTER_DOT;
    constexpr const int MAX_SIZE_OF_DOUBLE_PLUS_SIGN = MINUS_SIZE + MAX_SIZE_BEFORE_DOT + DOT_SIZE + MAX_SIZE_AFTER_DOT;

    constexpr const double MAX_DOUBLE_VAL = (std::numeric_limits<double>::max)();
    constexpr const double MIN_DOUBLE_VAL = (std::numeric_limits<double>::lowest)();

    constexpr const char* ERROR = "ERROR";
    constexpr const char* NOT_FOUND_IN_DATABUS = "NOT_FOUND_IN_DATABUS";
    constexpr const char* NOT_FOUND_IN_CACHE = "NOT_FOUND_IN_CACHE";
    constexpr const char* TO_BIG_IDX_FOR_CACHE = "TO_BIG_IDX_FOR_CACHE";
    constexpr const char* THIS_SHAPE_CANNOT_EXIST = "THIS_SHAPE_CANNOT_EXIST";
    constexpr const char* OVERFLOW_OR_UNDERFLOW = "OVERFLOW_OR_UNDERFLOW";
    constexpr const char* SHAPE_CAN_NOT_EXIST = "SHAPE_CAN_NOT_EXIST";
}

namespace cacheIdx
{
    constexpr const int POINTS_IDX = 0;
    constexpr const int SHAPES_IDX = 1;
}

namespace tupleIdx
{
    constexpr const int ARRAY = 0;
    constexpr const int SIZE = 1;
    constexpr const int INITIALIZED_MAP = 2;
}

using CShapeWithSize = std::tuple<CShape**, int, std::map<int, bool>&>;

namespace funs
{
    int toInt(char inChar);
    std::string toString(CODE inCode);

    bool isMinus(char inChar);
    bool isDot(char inChar);
    bool isOverMinLimit(std::string inChain);
    bool isOverMaxLimit(std::string inChain);
    bool is(std::string inChain);

    bool isInt(std::string inChain);
    bool isProperIdx(int inIdx, int inSize);
    bool isProperIdx(int idxOrAmount, CShapeWithSize inCache);
    bool isProperAmmountOfArgs(std::vector<std::string>& inCommand, int inProperAmountOfArgs);
    bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs);
    int sizeOf(double inVal);
    bool isOverflow(double inVal1, double inVal2);
    bool isSegmentToBig(double fstX, double sndX);
    bool isTriangleProper(double sideFst, double sideSnd, double sideThrd);

}

namespace idxOf
{
    namespace rectangle
    {
        constexpr const int SIDE_FST_IDX = 2;
        constexpr const int SIDE_SND_IDX = 3;
    }

    namespace triangle
    {
        constexpr const int SIDE_FST_IDX = 2;
        constexpr const int SIDE_SND_IDX = 3;
        constexpr const int SIDE_THRD_IDX = 4;
    }

    namespace trapezoid
    {
        constexpr const int SIDE_FST_IDX = 2;
        constexpr const int SIDE_SND_IDX = 3;
        constexpr const int LEG_FST_IDX = 4;
        constexpr const int LEG_SND_IDX = 5;
        constexpr const int HEIGHT_IDX = 6;
    }

    constexpr const int COMMAND = 0;
    constexpr const int ID_FOR_CREATE = 1;
    constexpr const int ID_OF_SHAPES = 1;
    constexpr const int NEW_NAME = 2;
    constexpr const int NEW_SIZE = 2;
    constexpr const int GOAL_ID = 2;
    constexpr const int COPY_TO = 1;
    constexpr const int COPY_FROM = 2;
    constexpr const int NEW_VAL = 3;
    constexpr const int X_AXIS_VAL = 2;
    constexpr const int Y_AXIS_VAL = 3;
    constexpr const int POINTS_FST = 2;
    constexpr const int POINT_SND = 3;
    constexpr const int INITIAL_NAME = 3;

    constexpr const int RECT_GOAL_ID = 1;

    constexpr const int POINT_SND_X = 4;
    constexpr const int POINT_SND_Y = 5;
}

namespace messageLiterals
{
    constexpr const char* GO = "go";
    constexpr const char* CREATE_POINT = "createPoint";
    constexpr const char* CREATE_POINT_COPY = "createPointCopy";
    constexpr const char* CREATE_RECT_POINTS = "createRectPoints";
    constexpr const char* CREATE_RECT_DEFAULT = "createRectDefault";

    constexpr const char* CREATE_RECT_DOUBLE = "createRect";
    constexpr const char* CREATE_SQUARE_DOUBLE = "createSquare";
    constexpr const char* CREATE_CIRCLE_DOUBLE = "createCircle";
    constexpr const char* CREATE_TRIANGLE_DOUBLE = "createTriangle";
    constexpr const char* CREATE_TRAPEZOID_DOUBLE = "createTrapezoid";
    
    constexpr const char* CREATE_RECT_COPY = "createRectCopy";
    constexpr const char* SET_POINT = "setPoint";
    constexpr const char* GET_POINT_X = "getPointX";
    constexpr const char* GET_POINT_Y = "getPointY";
    constexpr const char* CALCULATE_AREA = "calculateArea";
    constexpr const char* CALCULATE_AREAS = "calculateAreas";
    constexpr const char* CALCULATE_PERIMETER = "calculatePerimeter";
    constexpr const char* CALCULATE_PERIMETERS = "calculatePerimeters";
    constexpr const char* PRINT_ALL = "printAll";
    constexpr const char* SHOW_RECT = "showRect";
    constexpr const char* CLOSE = "close";
    constexpr const char* HELP = "help";
}

namespace commandArgs
{
    constexpr const char* IDX = "<idx>";
    constexpr const char* SIZE = "<size>";
    constexpr const char* NAME = "<name>";
    constexpr const char* VALUE = "<value>";
}

namespace fullCommands
{
    extern std::string goArgs;
    extern std::string createPointArgs;
    extern std::string createPointCopyArgs;
    extern std::string createRectPointsArgs;
    extern std::string createRectArgs;
    extern std::string createRectDefaultArgs;
    extern std::string createRectCopyArgs;
    extern std::string setPointArgs;
    extern std::string getPointXArgs;
    extern std::string getPointYArgs;
    extern std::string fieldRectArgs;
    extern std::string printAllArgs;
    extern std::string showRectArgs;
    extern std::string closeArgs;

    extern std::vector<std::string> all;
}
