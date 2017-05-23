#include <Algorithm.h>
#include "gtest/gtest.h"
#include "Generator.h"
using namespace std;

class GeneratorFixture : public ::testing::Test
{

};

TEST(GeneratorFixture, genetare_state_test)
{
    State state = Generator::GenerateState(3, 3, 5, 5);
    State org = state;

    State sorted = Algorithm::BruteForce(state);

    int i = 0;
}