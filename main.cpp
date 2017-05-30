#include <iostream>
#include <chrono>
#include <Generator.h>
#include "Algorithm.h"

int main()
{
    State state = Generator::GenerateState(30, 0.7, 10, 40);

    auto begin = std::chrono::high_resolution_clock::now();
    Algorithm::Heuristic(state, 1, Algorithm::quantity);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << endl;
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end-begin).count() << "ns" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    Algorithm::Heuristic(state, 2, Algorithm::quantity);
    end = std::chrono::high_resolution_clock::now();

    std::cout << endl;
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end-begin).count() << "ns" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    Algorithm::Heuristic(state, 1, Algorithm::density);
    end = std::chrono::high_resolution_clock::now();

    std::cout << endl;
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end-begin).count() << "ns" << std::endl;
}