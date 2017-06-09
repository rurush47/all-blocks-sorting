#include "Algorithm.h"

State Algorithm::BruteForce(State initial_state)
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

State Algorithm::Heuristic(State initial_state, int to_develop, Mode mode)
{
    vector<State> states;
    states.push_back(initial_state);

    vector<int> state_history;

    vector<int>indexes_to_develop;
    indexes_to_develop.push_back(0);

    while (true)
    {
        //develop states
        vector<State> to_add_states;
        for (int i = 0; i < indexes_to_develop.size(); ++i)
        {
            int crt_index = indexes_to_develop[i];
            State* current = &states[crt_index];

            //if is final return it
            if(State::IsFinal(*current))
            {
                return *current;
            }

            vector<State> new_states = current->GenerateNextStates(state_history);
            //erase state
            states.erase(states.begin() + crt_index);
            to_add_states.insert(to_add_states.end(), new_states.begin(), new_states.end());
        }

        states.insert(states.end(), to_add_states.begin(), to_add_states.end());

        //choose new states to develop
        vector<int> scores;
        indexes_to_develop.clear();
        //get all scores
        for (int j = 0; j < states.size(); ++j)
        {
            State* crt_state = &states[j];
            int state_score;
            if(mode == quantity)
            {
                state_score = BlocksQuantityScore(*crt_state);
                crt_state->SetScore(state_score);
            }
            else
            {
                state_score = BlockDensityScore(*crt_state);
                crt_state->SetScore(state_score);
            }
            scores.push_back(state_score);
        }

        indexes_to_develop = GetMinimalIndices(to_develop, scores);
    }
}

State Algorithm::Iterative(State initial_state)
{
    State state = initial_state;
    vector<Box> boxes = state.GetBoxes();

    while(!State::IsFinal(state))
    {
        for (int i = 0; i < boxes.size(); i++)
        {
            vector<int> current_blocks = boxes[i].GetBlocks();
            for (int j = 0; j < current_blocks.size(); ++j)
            {
                int current_value = current_blocks[j];
                if(current_value > 1)
                {
                    MoveToClosestFree(&state, i, j);
                }
            }
        }
    }

    return state;
}

void Algorithm::MoveToClosestFree(State *state, int box_index, int color_index)
{
    for (int i = 0; i < state->GetNumberOfBoxes(); ++i)
    {
        if(i != box_index)
        {
            Box new_box = state->GetBoxes()[i];
            if(!new_box.IsFull() && new_box.GetBlocks()[color_index] < 1)
            {
                state->GetBoxesRef()->at(box_index).RemoveBlock(color_index);
                state->GetBoxesRef()->at(i).AddBlock(color_index);
                return;
            }
        }
    }
}



vector<int> Algorithm::GetMinimalIndices(int quantity, vector<int> &scores)
{
    vector<int> indices;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
    for (int i = 0; i < scores.size(); ++i) {
        q.push(std::pair<int, int>(scores[i], i));
    }
    if(scores.size() < quantity)
    {
        quantity = scores.size();
    }
    for (int i = 0; i < quantity; ++i) {
        int ki = q.top().second;
        indices.push_back(ki);
        q.pop();
    }
    sort(indices.begin(), indices.end(), greater<int>());
    return indices;
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