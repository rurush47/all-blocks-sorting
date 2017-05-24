#ifndef ALL_BLOCKS_SORTING_STATE_H
#define ALL_BLOCKS_SORTING_STATE_H

#include <vector>
#include <string>
#include <functional>
#include "Box.h"
using namespace std;

class State
{
    int score = -1;
    int number_of_boxes;
    vector<Box> boxes;

public:
    State();
    State(int number_of_boxes, vector<Box>& boxes);
    string GenerateHash();
    const string GetHashString();
    vector<State> GenerateNextStates(vector<string>& state_history);
    vector<Box> GetBoxes();
    int GetNumberOfBoxes();
    static bool Contains(vector<string> hash_history, string hash);
    pair<bool, State> MoveLeft(int box_index, int color_index, State state);
    pair<bool, State> MoveRight(int box_index, int color_index, State state);
    static bool IsFinal(State& state);
    int GetScore();
    void SetScore(int new_score);
};


#endif //ALL_BLOCKS_SORTING_STATE_H
