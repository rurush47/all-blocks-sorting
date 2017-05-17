#include "Box.h"

Box::Box(vector<int> &blocks, int capacity)
{
    Box::blocks = blocks;
    Box::capacity = capacity;
}

vector<int> Box::GetBlocks() { return blocks; }

int Box::GetCapacity() { return capacity; }