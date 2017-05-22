#ifndef ALL_BLOCKS_SORTING_STATE_H
#define ALL_BLOCKS_SORTING_STATE_H

#include <vector>
#include <string>
#include "Box.h"
using namespace std;

class State
{
    int number_of_boxes;
    vector<Box> boxes;

public:
    State();
    State(int number_of_boxes, vector<Box>& boxes);
    int GenerateHash();
    vector<State> GenerateNextStates(vector<int>& state_history);
    vector<Box> GetBoxes();
    int GetNumberOfBoxes();
    static bool Contains(vector<int> hash_history, int hash);
    pair<bool, State> MoveLeft(int box_index, int color_index, State state);
    pair<bool, State> MoveRight(int box_index, int color_index, State state);
    static bool IsFinal(State& state);
};


#endif //ALL_BLOCKS_SORTING_STATE_H
