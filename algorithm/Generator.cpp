#include "Generator.h"

State Generator::GenerateState(int number_of_colors, float avg_density, int avg_capacity ,int number_of_boxes)
{
    srand (time(NULL));
    vector<int> zero_vector((unsigned)number_of_colors, 0);
    vector<Box> boxes;
    vector<int> color_quantity((unsigned)number_of_colors, 0);

    int color_sum = 0;
    int cap_sum = 0;

    default_random_engine generator;
    normal_distribution<INT32_C()> distribution((float)avg_density*((avg_capacity*number_of_boxes)/number_of_colors), 1.0);
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
        else if(number > number_of_boxes)
        {
            color_quantity.at(i) += number_of_boxes;
            color_sum += number_of_boxes;
        }
        else
        {
            color_quantity.at(i) += 1;
            color_sum += 1;
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
    State new_state(number_of_boxes, boxes);
    //PrintState(new_state);
    return new_state;
}

State Generator::GenerateStateDet(int number_of_colors, float density, int capacity, int number_of_boxes)
{
    srand (time(NULL));
    vector<int> zero_vector((unsigned)number_of_colors, 0);
    vector<Box> boxes;
    vector<int> color_quantity((unsigned)number_of_colors, 0);

    int color_sum = 0;
    int cap_sum = 0;

    //generate blocks
    for (int i = 0; i < number_of_colors; ++i)
    {
        int number = (int)round(density*capacity);
        if(number > 0 && number <= number_of_boxes)
        {
            color_quantity.at(i) += number;
            color_sum += number;
        }
        else if(number > number_of_boxes)
        {
            color_quantity.at(i) += number_of_boxes;
            color_sum += number_of_boxes;
        }
        else
        {
            color_quantity.at(i) += 1;
            color_sum += 1;
        }
    }

    //generate boxes
    for (int i = 0; i < number_of_boxes; ++i)
    {
        int cap = capacity;
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
    State new_state(number_of_boxes, boxes);
    //PrintState(new_state);
    return new_state;
}

State Generator::ReadFromFile(string path)
{
    string STRING;
    ifstream infile;
    infile.open (path);

    char n;
    infile >> n;
    int number_of_colors = n - '0';

    infile >> n;
    int number_of_boxes = n - '0';

    vector<int> zero_vec((unsigned)number_of_colors, 0);
    vector<Box> boxes;

    for (int i = 0; i < number_of_boxes; ++i)
    {
        infile >> n;
        int cap = n - '0';
        Box new_box(zero_vec, cap);
        for (int j = 0; j < number_of_colors; ++j)
        {
            infile >> n;
            int quantity = n - '0';
            for (int k = 0; k < quantity; ++k)
            {
                new_box.AddBlock(j);
            }
        }
        boxes.push_back(new_box);
    }

    State new_state(number_of_boxes, boxes);
    infile.close();
    return new_state;
}

void Generator::PrintState(State state)
{
    vector<Box> boxes = state.GetBoxes();
    int cap = 0;
    int color_count = 0;

    cout << endl;
    for (int i = 0; i < boxes.size(); ++i)
    {
        vector<int> blocks = boxes[i].GetBlocks();
        for (int j = 0; j < blocks.size(); ++j)
        {
            color_count += blocks[j];
            cout << blocks[j];
        }
        cout << " cap ";
        cap += boxes[i].GetCapacity();
        cout << boxes[i].GetCapacity();
        cout << endl;
    }
    cout << "total cap : ";
    cout << cap;
    cout << endl;
    cout << "total colors : ";
    cout << color_count;
    cout << endl;
}