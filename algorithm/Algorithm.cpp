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