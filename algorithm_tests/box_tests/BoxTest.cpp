#include "gtest/gtest.h"
#include "Box.h"
using namespace std;

class BoxFixture : public ::testing::Test
{

};

TEST(BoxFixture, constructor_test)
{
    vector<int> array = {1, 0, 2};
    Box box(array, 3);
    EXPECT_EQ(box.GetBlocks(), array);
    EXPECT_EQ(box.GetCapacity(), 3);
}