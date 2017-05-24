#include "State.h"

State::State() {}

State::State(int number_of_boxes, vector<Box>& boxes)
{
    State::number_of_boxes = number_of_boxes;
    State::boxes = boxes;
}

vector<Box> State::GetBoxes() { return boxes; }

int State::GetNumberOfBoxes() { return number_of_boxes; }

string State::GenerateHash()
{
    return GetHashString();
}

pair<bool, State> State::MoveLeft(int box_index, int color_index, State new_state)
{
    int next_box_index = box_index;
    box_index == 0 ? next_box_index = (number_of_boxes-1) : next_box_index--;
    if(new_state.boxes[box_index].RemoveBlock(color_index) &&
            new_state.boxes[next_box_index].AddBlock(color_index))
    {
        return pair<bool, State>(true, new_state);
    }
    return pair<bool, State>(false, State());
}

pair<bool, State> State::MoveRight(int box_index, int color_index, State new_state)
{
    int next_box_index = box_index;
    box_index == (number_of_boxes - 1) ? next_box_index = 0 : next_box_index++;
    if(new_state.boxes[box_index].RemoveBlock(color_index) &&
       new_state.boxes[next_box_index].AddBlock(color_index))
    {
        return pair<bool, State>(true, new_state);
    }
    return pair<bool, State>(false, State());
}

bool State::Contains(vector<string> hash_history, string hash)
{
    for(int i = 0; i < hash_history.size(); i++)
    {
        if(hash == hash_history[i])
        {
            return true;
        }
    }
    return false;
}

vector<State> State::GenerateNextStates(vector<string> &state_history)
{
    vector<State> new_states;
    for (int i = 0; i < number_of_boxes; ++i)
    {
        vector<int> crt_blocks = boxes[i].GetBlocks();
        for (int j = 0; j < crt_blocks.size(); ++j)
        {
            if(crt_blocks[j] > 0)
            {
                pair<bool, State> move_results[2] = {MoveLeft(i, j, *this), MoveRight(i, j, *this)};
                for(int i = 0; i < 2; i++)
                {
                    if(move_results[i].first)
                    {
                        State new_state = move_results[i].second;
                        string hash = new_state.GenerateHash();
                        if(!Contains(state_history, hash))
                        {
                            state_history.push_back(hash);
                            new_states.push_back(new_state);
                        }
                    }
                }
            }
        }
    }
    return new_states;
}

bool State::IsFinal(State& state)
{
    vector<Box> boxes = state.GetBoxes();
    for (int i = 0; i < boxes.size(); ++i)
    {
        vector<int> blocks = boxes[i].GetBlocks();
        for (int j = 0; j < blocks.size(); ++j)
        {
            if(blocks[j] > 1)
            {
                return false;
            }
        }
    }
    return true;
}

void State::SetScore(int new_score) { State::score = new_score; }

int State::GetScore() { return score; }

const string State::GetHashString()
{
    string result_string = "";
    for (int i = 0; i < boxes.size(); ++i)
    {
        vector<int> crt_box_array = boxes[i].GetBlocks();
        for (int j = 0; j < crt_box_array.size(); j++)
        {
            result_string += to_string(crt_box_array[j]);
        }
        result_string += "|";
    }
    return result_string;
}

