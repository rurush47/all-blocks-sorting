#include "gtest/gtest.h"
#include "Box.h"

class BoxFixture : public ::testing::Test
{

};

TEST(BoxFixture, test1)
{
    Box* box = new Box(5);
    delete(box);
    EXPECT_EQ(1, 1);
}

TEST(BoxFixture, test2)
{
    EXPECT_EQ(1, 0);
}