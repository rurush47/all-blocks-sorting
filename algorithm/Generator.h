#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>
#include <fstream>
#include "State.h"
#include "Box.h"

class Generator
{
public:
    static State GenerateState(int number_of_colors, float avg_density, int avg_capacity, int number_of_boxes);
    static State GenerateStateDet(int number_of_colors, float density, int capacity, int number_of_boxes);
    static State ReadFromFile(string path);
    static void PrintState(State state);
};
