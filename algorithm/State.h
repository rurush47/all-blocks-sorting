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
    size_t GenerateHash();
    const string GetHashString();
    vector<State> GenerateNextStates(vector<int>& state_history);
    vector<Box> GetBoxes();
    vector<Box> * GetBoxesRef();
    int GetNumberOfBoxes();
    static bool Contains(vector<int> hash_history, int hash);
    pair<bool, State> MoveLeft(int box_index, int color_index, State state);
    pair<bool, State> MoveRight(int box_index, int color_index, State state);
    static bool IsFinal(State& state);
    int GetScore();
    void SetScore(int new_score);
};


#endif //ALL_BLOCKS_SORTING_STATE_H
