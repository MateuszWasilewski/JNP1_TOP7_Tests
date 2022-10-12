#include "gtest/gtest.h"
#include "TestInput.h"

namespace Testing {

class Error : 
    public Testing::CommonFixture,
    public ::testing::TestWithParam<std::string>
{
};

TEST_P(Error, ExpectError) {
    auto& line = GetParam();
    auto operation = Input::ParseInput(musicList, line);
    EXPECT_TRUE(std::holds_alternative<Input::Error>(operation));
}

INSTANTIATE_TEST_CASE_P(
    InputTests,
    Error,
    ::testing::Values(
        "A 1",
        "   NEW   ",
        "   Top   ",
        "   NEW    9999999999999999999999   ",
        "   NEW    01   ",
        " a   ",
        "  01",
        "   1  999999999",
        "999999999 10",
        "\t  100000000"
    ));

}