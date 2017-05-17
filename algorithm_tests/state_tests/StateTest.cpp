#include <gtest/gtest.h>
#include <vector>
#include "Box.h"
#include "State.h"

class StateFixture: public ::testing::Test
{

};

TEST(StateFixture, constructor_test)
{
    int array1[] = {1, 2, 1};
    int array2[] = {1, 2, 1};
    int array3[] = {1, 2, 1};
    int array4[] = {1, 2, 1};

    Box box1(array1, 3);
    Box box2(array2, 3);
    Box box3(array3, 3);
    Box box4(array4, 3);

    vector<Box> box_vector;
    box_vector.push_back(box1);
    box_vector.push_back(box2);
    box_vector.push_back(box3);
    box_vector.push_back(box4);

    State state(4, box_vector);
    Box box_x = state.GetBoxes()[0];
    Box box_y = box1;

    ASSERT_EQ(state.GetNumberOfBoxes(), 4);
    ASSERT_EQ(box_x.GetBlocks(), box_y.GetBlocks());
}

TEST(StateFixture, generate_hash_test)
{
    int array1[] = {1, 2, 1};
    int array2[] = {1, 2, 3};
    int array3[] = {1, 2, 6};
    int array4[] = {1, 2, 7};
    int array5[] = {1, 2, 1};
    int array6[] = {1, 2, 3};

    Box box1(array1, 3);
    Box box2(array2, 3);
    Box box3(array3, 3);
    Box box4(array4, 3);
    Box box5(array5, 3);
    Box box6(array6, 3);

    vector<Box> box_vector;
    box_vector.push_back(box1);
    box_vector.push_back(box2);

    vector<Box> box_vector2;
    box_vector2.push_back(box5);
    box_vector2.push_back(box6);

    vector<Box> box_vector3;
    box_vector3.push_back(box3);
    box_vector3.push_back(box4);

    State state(4, box_vector);
    State state2(4, box_vector2);
    State state3(4, box_vector3);

    state.GenerateHash();

    ASSERT_EQ(state.GenerateHash(), state3.GenerateHash());
    ASSERT_NE(state.GenerateHash(), state2.GenerateHash());
}
