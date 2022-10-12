#include "gtest/gtest.h"
#include "TestInput.h"

namespace Testing {

class DoNothing : 
    public ::Testing::CommonFixture,
    public ::testing::TestWithParam<std::string>
{
};

TEST_P(DoNothing, ExpectDoNothing) {
    auto& line = GetParam();
    auto operation = Input::ParseInput(musicList, line);
    EXPECT_TRUE(std::holds_alternative<Input::DoNothing>(operation));
}

INSTANTIATE_TEST_CASE_P(
    InputTests,
    DoNothing,
    ::testing::Values(
        "",
        "      ",
        "      \t \r \t"
    ));

}
