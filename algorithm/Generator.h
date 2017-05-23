#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include "State.h"
#include "Box.h"

class Generator
{
public:
    static State GenerateState(int number_of_colors, int avg_density, int avg_capacity, int number_of_boxes);
};
