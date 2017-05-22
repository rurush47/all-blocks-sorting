#include <gtest/gtest.h>
#include "Algorithm.h"

class AlgorithmFixture :public ::testing::Test
{

};

TEST(AlgorithmFixture, brute_force_test)
{
    vector<int> blocks1 = {1, 0, 2, 3};
    vector<int> blocks2 = {1, 2, 0, 0};
    vector<int> blocks3 = {1, 1, 1, 0};

    Box box1(blocks1, 4);
    Box box2(blocks2, 4);
    Box box3(blocks3, 4);

    vector<Box> box_vec;
    box_vec.push_back(box1);
    box_vec.push_back(box2);
    box_vec.push_back(box3);

    State state(3, box_vec);

    State sorted_state = Algorithm::BruteForce(state);

    vector<int> block_res = {1, 1, 1, 1};

    ASSERT_TRUE(sorted_state.GetBoxes()[0].GetBlocks() == block_res);
    ASSERT_TRUE(sorted_state.GetBoxes()[1].GetBlocks() == block_res);
    ASSERT_TRUE(sorted_state.GetBoxes()[2].GetBlocks() == block_res);
}

TEST(AlgorithmFixture, quantity_score_test)
{
    vector<int> blocks1 = {1, 0, 2, 3};
    vector<int> blocks2 = {1, 2, 0, 0};
    vector<int> blocks3 = {1, 1, 1, 0};

    Box box1(blocks1, 4);
    Box box2(blocks2, 4);
    Box box3(blocks3, 4);

    vector<Box> box_vec;
    box_vec.push_back(box1);
    box_vec.push_back(box2);
    box_vec.push_back(box3);

    State state(3, box_vec);

    int score = Algorithm::BlocksQuantityScore(state);

    ASSERT_EQ(score, 4);
}