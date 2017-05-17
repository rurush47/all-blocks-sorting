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
    int result = 9999;
//    for (int i = 0; i < boxes.size(); ++i)
//    {
//        int* crt_box_array = boxes[i].GetBlocks();
//        int size = (sizeof(crt_box_array)/sizeof(*crt_box_array));
//        for (int j = 0; j < size; j++)
//        {
//            result ^= crt_box_array[j];
//        }
//    }
    return result;
}