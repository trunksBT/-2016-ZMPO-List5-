
#include <gtest/gtest.h>

#include <limits>
#include <vector>

#include <Bridges/BridgesModel.hpp>
#include <Utils/Utils.hpp>
#include <Bridges/RectangleAreaBridge.hpp>
#include <Bridges/RectanglePerimeterBridge.hpp>

using namespace defaultVals;
using namespace bridgeModelKeys;

namespace
{
struct CBridgesUT : public testing::Test
{
    const char* RANDOM_KEY_1 = "NoSiema";
    const char* RANDOM_KEY_2 = "Jol";
};

TEST_F(CBridgesUT, CreateWithDefaultCTOR)
{
    BridgesModel tempBridges;

    ASSERT_EQ(0, tempBridges.size());
}

TEST_F(CBridgesUT, CreateWithParamCTOR)
{
    BridgesModel tempBridges(
    { { rectangle::AREA, new CRectangleAreaBridge() }, { rectangle::PERIMETER, new CRectanglePerimeterBridge() } });

    ASSERT_EQ(2, tempBridges.size());
}

TEST_F(CBridgesUT, CreateWithCopyCTOR)
{
    BridgesModel tempBridges(
    { { rectangle::AREA, new CRectangleAreaBridge() },{ rectangle::PERIMETER, new CRectanglePerimeterBridge() } });

    BridgesModel afterCloneBridges(tempBridges);

    ASSERT_EQ(2, tempBridges.size());
    ASSERT_EQ(2, afterCloneBridges.size());
}

TEST_F(CBridgesUT, CreateWithDefaultCTOR_UpdateTwiceTheSame)
{
    BridgesModel tempBridges;
    tempBridges.update(RANDOM_KEY_1, new CRectanglePerimeterBridge());
    tempBridges.update(RANDOM_KEY_1, new CRectangleAreaBridge());

    ASSERT_EQ(1, tempBridges.size());
}

TEST_F(CBridgesUT, CreateWithDefaultCTOR_UpdateTwice_OtherKeys)
{
    BridgesModel tempBridges;
    tempBridges.update(RANDOM_KEY_1, new CRectanglePerimeterBridge());
    tempBridges.update(RANDOM_KEY_2, new CRectangleAreaBridge());

    ASSERT_EQ(2, tempBridges.size());
}

TEST_F(CBridgesUT, CreateWithDefaultCTOR_UpdateTwice_OtherKeys_And_Fetch)
{
    BridgesModel tempBridges;
    tempBridges.update(RANDOM_KEY_1, new CRectanglePerimeterBridge());
    tempBridges.update(RANDOM_KEY_2, new CRectangleAreaBridge());

    const IBridge& fetchedVal = tempBridges.fetch(RANDOM_KEY_1);

    ASSERT_EQ(2, tempBridges.size());
}

TEST_F(CBridgesUT, CreateWithDefaultCTOR_UpdateTwice_OtherKeys_And_Fetch_And_Remove)
{
    BridgesModel tempBridges;
    tempBridges.update(RANDOM_KEY_1, new CRectanglePerimeterBridge());
    tempBridges.update(RANDOM_KEY_2, new CRectangleAreaBridge());

    const IBridge& fetchedVal = tempBridges.fetch(RANDOM_KEY_1);

    tempBridges.removeKey(RANDOM_KEY_1);

    ASSERT_EQ(1, tempBridges.size());
}

TEST_F(CBridgesUT, InfoModel_count)
{
    DataBus tempBridges=
    {
        { RANDOM_KEY_1, 3 },
        { RANDOM_KEY_2, 4 }

    };

    ASSERT_EQ(1, tempBridges.count(RANDOM_KEY_1));
}
}
