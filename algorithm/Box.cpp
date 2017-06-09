#include "Box.h"

Box::Box(vector<int> blocks, int capacity)
{
    Box::blocks = blocks;
    Box::capacity = capacity;
    Box::number_of_blocks = 0;
}

vector<int> Box::GetBlocks() { return blocks; }

int Box::GetCapacity() { return capacity; }

int Box::GetNumberOfBlocks() { return number_of_blocks; }

bool Box::AddBlock(int color)
{
    try
    {
        if(number_of_blocks < capacity)
        {
            blocks.at(color)++;
            number_of_blocks++;
            return true;
        }
    }
    catch (const out_of_range& oor)
    {
        throw oor;
    }
    return false;
}

bool Box::RemoveBlock(int color)
{
    try
    {
        if(blocks.at(color) > 0)
        {
            blocks.at(color)--;
            number_of_blocks--;
            return true;
        }
    }
    catch (const out_of_range& oor)
    {
        throw oor;
    }
    return false;
}

bool Box::IsFull()
{
    return number_of_blocks >= capacity;
}