#ifndef ALL_BLOCKS_SORTING_ALGORITHM_H
#define ALL_BLOCKS_SORTING_ALGORITHM_H

#include "State.h"
#include <queue>
#include <functional>
#include <algorithm>

class Algorithm
{
    int number_of_colors;
public:
    enum Mode {quantity, density};
    static State BruteForce(State initial_state);
    static State Heuristic(State initial_state, int states_to_develop, Mode mode);
    static int BlocksQuantityScore(State& state);
    static int BlockDensityScore(State& state);
    static vector<int> GetMinimalIndices(int quantity, vector<int> &scores);
};


#endif //ALL_BLOCKS_SORTING_ALGORITHM_H
