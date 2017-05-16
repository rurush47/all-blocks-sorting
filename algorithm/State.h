#ifndef ALL_BLOCKS_SORTING_STATE_H
#define ALL_BLOCKS_SORTING_STATE_H

#include <vector>
#include <string>
#include "Box.h"
using namespace std;

class State
{
    int number_of_boxes;
    //vector<Box> boxes;

public:
    State(int number_of_boxes, vector<Box> boxes);
    string GenerateHash();
    bool IsFinal();
    //vector<State> GenerateNextStates(vector<string> state_history);
    //TODO heuristic evaluation
};


#endif //ALL_BLOCKS_SORTING_STATE_H
