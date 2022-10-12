#include "gtest/gtest.h"
#include "TestInput.h"
#include <tuple>

namespace Testing {

class TestVotes : 
    public ::Testing::CommonFixture,
    public ::testing::TestWithParam<std::tuple<std::string, Votes>>
{
};

TEST_P(TestVotes, ExpectVotes) {
    auto& [line, result] = GetParam();
    auto operation = Input::ParseInput(musicList, line);
    ASSERT_TRUE(std::holds_alternative<Votes>(operation));

    auto& ans = std::get<Votes>(operation);
    EXPECT_EQ(ans, result);
}

INSTANTIATE_TEST_CASE_P(
    InputTests,
    TestVotes,
    ::testing::Values(
        std::make_tuple("7", Votes{7}),
        std::make_tuple(" 1  3  ", Votes{1, 3}),
        std::make_tuple(" 1 93764 3  212   \t", Votes{1, 93764, 3, 212})
    ));

}
