#include <gtest/gtest.h>
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
    vector<int> array7 = {1, 2, 3};
    vector<int> array8 = {1, 2, 2};

    Box box1(array1, 3);
    Box box2(array2, 3);
    Box box3(array3, 3);
    Box box4(array4, 3);
    Box box5(array5, 3);
    Box box6(array6, 3);
    Box box7(array7, 3);
    Box box8(array8, 3);

    vector<Box> box_vector;
    box_vector.push_back(box1);
    box_vector.push_back(box2);

    vector<Box> box_vector2;
    box_vector2.push_back(box5);
    box_vector2.push_back(box6);

    vector<Box> box_vector3;
    box_vector3.push_back(box3);
    box_vector3.push_back(box4);

    vector<Box> box_vector4;
    box_vector4.push_back(box7);
    box_vector4.push_back(box8);

    State state(4, box_vector);
    State state2(4, box_vector2);
    State state3(4, box_vector3);
    State state4(4, box_vector4);

    state.GenerateHash();

    int hash1 = state.GenerateHash();
    int hash2 = state2.GenerateHash();
    int hash3 = state3.GenerateHash();
    int hash4 = state4.GenerateHash();

    ASSERT_EQ(hash1, hash2);
    ASSERT_NE(hash1, hash3);
    ASSERT_NE(hash1, hash4);
}
