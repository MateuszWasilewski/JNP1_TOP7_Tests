#include "gtest/gtest.h"
#include "TestInput.h"
#include <tuple>

namespace Testing {

class TestNewMax : 
    public ::Testing::CommonFixture,
    public ::testing::TestWithParam<std::tuple<std::string, Number>>
{
};

TEST_P(TestNewMax, ExpectNewMax) {
    auto& [line, result] = GetParam();
    auto operation = Input::ParseInput(musicList, line);
    ASSERT_TRUE(std::holds_alternative<Number>(operation));

    auto& ans = std::get<Number>(operation);
    EXPECT_EQ(ans, result);
}

INSTANTIATE_TEST_CASE_P(
    InputTests,
    TestNewMax,
    ::testing::Values(
        std::make_tuple("NEW 7", 7),
        std::make_tuple(" NEW 3  ", 3),
        std::make_tuple(" \t NEW 99999999", 99999999)
    ));

}
