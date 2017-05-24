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

    string hash1 = state.GenerateHash();
    string hash2 = state2.GenerateHash();
    string hash3 = state3.GenerateHash();
    string hash4 = state4.GenerateHash();

    ASSERT_EQ(hash1, hash2);
    ASSERT_NE(hash1, hash3);
    ASSERT_NE(hash1, hash4);
}

TEST(StateFixture, contains_test)
{
    vector<string> v;
    v.push_back("12");
    v.push_back("45");
    v.push_back("19");

    bool result1 = State::Contains(v, "12");
    bool result2 = State::Contains(v, "23");

    ASSERT_EQ(result1, true);
    ASSERT_EQ(result2, false);
}

TEST(StateFixture, move_left_test) {
    vector<int> vector1 = {0, 0, 0};
    vector<int> vector2 = {1, 0, 0};

    Box box1(vector1, 3);
    Box box2(vector2, 3);

    vector<Box> box_list;
    box_list.push_back(box1);
    box_list.push_back(box2);

    State state(2, box_list);

    pair<bool, State> new_state = state.MoveLeft(1, 0, state);
    ASSERT_EQ(new_state.first, true);
    ASSERT_EQ(new_state.second.GetBoxes()[0].GetBlocks()[0], 1);
    ASSERT_EQ(new_state.second.GetBoxes()[0].GetBlocks()[1], 0);
}

TEST(StateFixture, move_right_test) {
    vector<int> vector1 = {0, 0, 0};
    vector<int> vector2 = {0, 0, 1};

    Box box1(vector1, 3);
    Box box2(vector2, 3);

    vector<Box> box_list;
    box_list.push_back(box1);
    box_list.push_back(box2);

    State state(2, box_list);

    pair<bool, State> new_state = state.MoveRight(1, 2, state);
    ASSERT_EQ(new_state.first, true);
    ASSERT_EQ(new_state.second.GetBoxes()[0].GetBlocks()[2], 1);
    ASSERT_EQ(new_state.second.GetBoxes()[1].GetBlocks()[2], 0);
}

TEST(StateFixture, generate_states_test)
{
    vector<int> vector1 = {2, 1, 1};
    vector<int> vector2 = {0, 1, 1};

    Box box1(vector1, 10);
    Box box2(vector2, 10);

    vector<Box> box_list;
    box_list.push_back(box1);
    box_list.push_back(box2);

    State state(2, box_list);

    vector<string> state_history;
    vector<State> new_states = state.GenerateNextStates(state_history);

    vector<int> res = {1, 1, 1};

    ASSERT_EQ(new_states.size(), 5);
    ASSERT_EQ(new_states[0].GetBoxes()[1].GetBlocks(), res);
}

TEST(StateFixture, generate_states_size_cap_test)
{

    vector<int> vector1 = {0, 0, 0};
    vector<int> vector2 = {0, 0, 0};

    Box box1(vector1, 3);
    Box box2(vector2, 2);

    box1.AddBlock(0);
    box1.AddBlock(0);

    box2.AddBlock(1);
    box2.AddBlock(2);

    vector<Box> box_list;
    box_list.push_back(box1);
    box_list.push_back(box2);

    State state(2, box_list);

    vector<string> state_history;
    vector<State> new_states = state.GenerateNextStates(state_history);

    vector<int> res = {2, 0, 1};

    ASSERT_EQ(new_states.size(), 2);
    ASSERT_EQ(new_states[1].GetBoxes()[0].GetBlocks(), res);
}

TEST(StateFixture, is_final_test)
{
    vector<int> vector1 = {1, 0, 1};
    vector<int> vector2 = {1, 1, 1};

    vector<int> vector3 = {1, 2, 1};
    vector<int> vector4 = {1, 1, 1};

    Box box1(vector1, 3);
    Box box2(vector2, 2);

    Box box3(vector3, 3);
    Box box4(vector4, 3);

    vector<Box> box_list;
    box_list.push_back(box1);
    box_list.push_back(box2);

    vector<Box> box_list2;
    box_list2.push_back(box3);
    box_list2.push_back(box4);

    State state(2, box_list);
    State state2(2, box_list2);

    ASSERT_EQ(State::IsFinal(state), true);
    ASSERT_EQ(State::IsFinal(state2), false);
}

TEST(StateFixture, generate_hash_string_test) {
    vector<int> vector1 = {0, 2, 0};
    vector<int> vector2 = {1, 0, 0};

    Box box1(vector1, 3);
    Box box2(vector2, 3);

    vector<Box> box_list;
    box_list.push_back(box1);
    box_list.push_back(box2);

    State state(2, box_list);

    string hash_string = state.GetHashString();

    ASSERT_EQ(hash_string, "020|100|");
}
