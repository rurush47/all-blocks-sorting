#include "State.h"

State::State(int number_of_boxes, vector<Box>& boxes)
{
    State::number_of_boxes = number_of_boxes;
    State::boxes = boxes;
}

vector<Box> State::GetBoxes() { return boxes; }

int State::GetNumberOfBoxes() { return number_of_boxes; }

int State::GenerateHash()
{
    int result = 0;
    int shift = 0;
    for (int i = 0; i < boxes.size(); ++i)
    {
        vector<int> crt_box_array = boxes[i].GetBlocks();
        for (int j = 0; j < crt_box_array.size(); j++)
        {
            shift = (shift + 11) % 21;
            result ^= (crt_box_array[j] + 1024) << shift;
        }
    }
    return result;
}

State State::MoveLeft(int box_index, int color_index)
{
    Box box = boxes[box_index];
    int next_box_index;
    box_index == 0 ? next_box_index = number_of_boxes : next_box_index--;
    State new_state = *this;
}

State State::MoveRight(int box_index, int color_index)
{

}

//TODO implement
vector<State> State::GenerateNextStates(vector<string> &state_history)
{
    vector<State> new_states;
    for (int i = 0; i < number_of_boxes; ++i)
    {
        vector<int> crt_blocks = boxes[i].GetBlocks();
        for (int j = 0; j < crt_blocks.size(); ++j)
        {

        }
    }
}