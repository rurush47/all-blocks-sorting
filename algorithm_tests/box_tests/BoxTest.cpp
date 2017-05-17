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

TEST(BoxFixture, add_block_test)
{
    vector<int> array = {1, 1, 2};
    Box box(array, 3);
    bool result = box.AddBlock(1);
    int val = box.GetBlocks()[1];
    ASSERT_TRUE(result);
    ASSERT_THROW(box.AddBlock(4), out_of_range);
    ASSERT_EQ(val, 2);
}

TEST(BoxFixture, remove_block_test)
{
    vector<int> array = {1, 1, 3};
    Box box(array, 3);
    bool result = box.RemoveBlock(2);
    int val = box.GetBlocks()[2];
    ASSERT_TRUE(result);
    ASSERT_THROW(box.RemoveBlock(4), out_of_range);
    ASSERT_EQ(val, 2);
}