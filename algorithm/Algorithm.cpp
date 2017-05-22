#include "Algorithm.h"

State Algorithm::BruteForce(State &initial_state)
{
    vector<State> unchecked_states;
    unchecked_states.push_back(initial_state);

    vector<int> state_history;

    State current_state = initial_state;
    while(!State::IsFinal(current_state))
    {
        int state_hash = current_state.GenerateHash();
        state_history.push_back(state_hash);

        vector<State> new_states = current_state.GenerateNextStates(state_history);
        unchecked_states.erase(unchecked_states.begin());
        unchecked_states.insert(unchecked_states.end(), new_states.begin(), new_states.end());

        current_state = unchecked_states[0];
    }
    return current_state;
}

int Algorithm::BlocksQuantityScore(State &state)
{
    int score = 0;

    vector<Box> boxes = state.GetBoxes();
    for (int i = 0; i < boxes.size(); ++i)
    {
        vector<int >current_blocks = boxes[i].GetBlocks();
        for (int j = 0; j < current_blocks.size(); ++j)
        {
            int ctr_quantity = current_blocks[j];
            if(ctr_quantity > 1)
            {
                score += ctr_quantity - 1;
            }
        }
    }
    return score;
}

int Algorithm::BlockDensityScore(State &state)
{
    int score = 0;

    vector<Box> boxes = state.GetBoxes();
    for (int i = 0; i < boxes.size(); ++i)
    {
        Box current_box = boxes[i];
        vector<int>current_blocks = boxes[i].GetBlocks();
        if(current_box.GetNumberOfBlocks() == current_box.GetCapacity())
        {
            score++;
        }
        for (int j = 0; j < current_blocks.size(); ++j)
        {
            int ctr_quantity = current_blocks[j];
            if(ctr_quantity > 1)
            {
                score += ctr_quantity - 1;
            }
        }
    }
    return score;
}