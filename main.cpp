#include <iostream>
#include "algorithm/Box.h"

int main()
{
    Box* box = new Box(5);
    delete(box);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}