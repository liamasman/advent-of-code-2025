#include "days/day_nine.h"
#include <gtest/gtest.h>

using namespace aoc25::days;

TEST(DayNineTest, PartOneExample)
{
    const std::string input{
        "7,1\n"
        "11,1\n"
        "11,7\n"
        "9,7\n"
        "9,5\n"
        "2,5\n"
        "2,3\n"
        "7,3"
    };

    const DayNine day_nine{};
    EXPECT_EQ(day_nine.partOne(input), "50");
}

TEST(DayNineTest, PartTwoExample)
{
    const std::string input{
        "7,1\n"
        "11,1\n"
        "11,7\n"
        "9,7\n"
        "9,5\n"
        "2,5\n"
        "2,3\n"
        "7,3"
    };

    const DayNine day_nine{};
    EXPECT_EQ(day_nine.partTwo(input), "24");
}
