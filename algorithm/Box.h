#ifndef ALL_BLOCKS_SORTING_BOX_H
#define ALL_BLOCKS_SORTING_BOX_H

#include <vector>
#include <exception>
#include <typeinfo>
#include <iostream>
using namespace std;

class Box
{
    vector<int> blocks;
    int capacity;
    int number_of_blocks;
public:
    Box(vector<int> &blocks, int capacity);
    vector<int> GetBlocks();
    int GetCapacity();
    int GetNumberOfBlocks();
    bool AddBlock(int color);
    bool RemoveBlock(int color);
};


#endif //ALL_BLOCKS_SORTING_BOX_H
