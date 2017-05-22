#ifndef ALL_BLOCKS_SORTING_ALGORITHM_H
#define ALL_BLOCKS_SORTING_ALGORITHM_H

#include "State.h"

class Algorithm
{
    int number_of_colors;
public:
    static State BruteForce(State& initial_state);
    static State Heuristic(State& initial_state);
    static int BlocksQuantityScore(State& state);
    static int BlockDensityScore(State& state);
};


#endif //ALL_BLOCKS_SORTING_ALGORITHM_H
