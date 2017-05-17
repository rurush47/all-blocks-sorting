#include <gtest/gtest.h>
#include <vector>
#include "Box.h"
#include "State.h"
using namespace std;

class StateFixture: public ::testing::Test
{

};

TEST(StateFixture, constructor_test)
{
    vector<int> array1 = {1, 2, 1};
    vector<int> array2 = {1, 2, 1};
    vector<int> array3 = {1, 2, 1};
    vector<int> array4 = {1, 2, 1};

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
    vector<int> array1 = {1, 2, 1};
    vector<int> array2 = {1, 2, 3};
    vector<int> array3 = {1, 2, 6};
    vector<int> array4 = {1, 2, 7};
    vector<int> array5 = {1, 2, 1};
    vector<int> array6 = {1, 2, 3};

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

    int hash1 = state.GenerateHash();
    int hash2 = state2.GenerateHash();
    int hash3 = state3.GenerateHash();

    ASSERT_EQ(state.GenerateHash(), state2.GenerateHash());
    ASSERT_NE(state.GenerateHash(), state3.GenerateHash());
}
