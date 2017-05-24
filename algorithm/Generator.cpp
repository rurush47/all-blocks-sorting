#include "Generator.h"

State Generator::GenerateState(int number_of_colors, int avg_density, int avg_capacity ,int number_of_boxes)
{
    srand (time(NULL));
    if(number_of_boxes < number_of_colors)
    {
        throw "Bad numbers!";
    }

    vector<int> zero_vector((unsigned)number_of_colors, 0);
    vector<Box> boxes;
    vector<int> color_quantity((unsigned)number_of_colors, 0);

    int color_sum = 0;
    int cap_sum = 0;

    default_random_engine generator;
    normal_distribution<INT32_C()> distribution((float)avg_density, 1.0);
    normal_distribution<INT32_C()> distribution_boxes((float)avg_capacity, 1.0);

    //generate blocks
    for (int i = 0; i < number_of_colors; ++i)
    {
        int number = distribution(generator);
        if(number > 0 && number <= number_of_boxes)
        {
            color_quantity.at(i) += number;
            color_sum += number;
        }
        else
        {
            i--;
        }
    }

    //generate boxes
    for (int i = 0; i < number_of_boxes; ++i)
    {
        int cap = distribution_boxes(generator);
        Box new_box(zero_vector, cap);
        boxes.push_back(new_box);
        cap_sum += cap;
    }

    if(cap_sum < color_sum)
    {
        throw "Bad numbers!";
    }

    //distribute colors
    for (int j = 0; j < number_of_colors; ++j)
    {
        int crt_color = color_quantity[j];
        for (int i = 0; i < crt_color; ++i)
        {
            int number = rand() % number_of_boxes;
            if(!boxes[number].AddBlock(j))
            {
                i--;
            }
        }
    }

    //create state
    return State(number_of_boxes, boxes);
}