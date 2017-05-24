#include <Algorithm.h>
#include "gtest/gtest.h"
#include "Generator.h"
using namespace std;

class GeneratorFixture : public ::testing::Test
{

};

TEST(GeneratorFixture, genetare_state_test)
{
    State state = Generator::GenerateState(5, 5, 5, 5);
    State org = state;

    State sorted = Algorithm::Heuristic(state, 1, Algorithm::quantity);

    int i = 0;
}