#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "ExampleMock.hpp"
// #include "ExampleStuff.hpp"

namespace sample_test
{
using namespace ::testing;

struct ExampleFixture : public ::testing::Test
{

};

TEST_F(ExampleFixture, sampleTest)
{
    // NiceMock<ExampleMock> exampleMock;
    // Example example;
    ASSERT_TRUE(true);
}

}