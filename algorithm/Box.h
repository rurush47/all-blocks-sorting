#ifndef ALL_BLOCKS_SORTING_BOX_H
#define ALL_BLOCKS_SORTING_BOX_H

#include <vector>
using namespace std;

class Box
{
    vector<int> blocks;
    int capacity;
public:
    Box(vector<int> &blocks, int capacity);
    vector<int> GetBlocks();
    int GetCapacity();
};


#endif //ALL_BLOCKS_SORTING_BOX_H
