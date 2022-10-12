#include "gtest/gtest.h"
#include "TestInput.h"

namespace Testing {

class Top : 
    public ::Testing::CommonFixture,
    public ::testing::TestWithParam<std::string>
{
};

TEST_P(Top, ExpectTop) {
    auto& line = GetParam();
    auto operation = Input::ParseInput(musicList, line);
    EXPECT_TRUE(std::holds_alternative<Input::Top>(operation));
}

INSTANTIATE_TEST_CASE_P(
    InputTests,
    Top,
    ::testing::Values(
        "TOP",
        "TOP   ",
        "    TOP    ",
        "  \r   TOP   \t  "
    ));

}
