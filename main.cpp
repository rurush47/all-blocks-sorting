#include <iostream>
#include <chrono>
#include <Generator.h>
#include "Algorithm.h"
using namespace std;

int main()
{
    State state;
    int n = 8;
    int number_of_colors = n;
    float density = 0.5;
    int cap = n;
    int number_of_boxes = n;
    int number_of_tests = 100;

    State ex_state = Generator::GenerateStateDet(number_of_colors, density, cap, number_of_boxes);
    Generator::PrintState(ex_state);

    cout << "iterative" << endl;

    for (int i = 0; i < number_of_tests; ++i)
    {
        state = Generator::GenerateStateDet(number_of_colors, density, cap, number_of_boxes);

        State final_state = Algorithm::Heuristic(state, 1, Algorithm::quantity);

        std::cout << final_state.GetNumberOfMoves() << std::endl;
    }

    cout << "heuristic quantity 1" << endl;

//    for (int i = 0; i < number_of_tests; ++i) {
//        state = Generator::GenerateStateDet(number_of_colors, density, cap, number_of_boxes);
//
//        auto begin = std::chrono::high_resolution_clock::now();
//        Algorithm::Heuristic(state, 1, Algorithm::quantity);
//        auto end = std::chrono::high_resolution_clock::now();
//
//        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << std::endl;
//    }
//
//    cout << "heuristic density 1" << endl;
//
//    for (int i = 0; i < number_of_tests; ++i) {
//        state = Generator::GenerateStateDet(number_of_colors, density, cap, number_of_boxes);
//
//        auto begin = std::chrono::high_resolution_clock::now();
//        Algorithm::Heuristic(state, 1, Algorithm::density);
//        auto end = std::chrono::high_resolution_clock::now();
//
//        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << std::endl;
//    }

//    cout << "brute force" << endl;
//
//    for (int i = 0; i < number_of_tests; ++i) {
//        state = Generator::GenerateStateDet(number_of_colors, density, cap, number_of_boxes);
//
//        auto begin = std::chrono::high_resolution_clock::now();
//        Algorithm::BruteForce(state);
//        auto end = std::chrono::high_resolution_clock::now();
//
//        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << std::endl;
//    }
}