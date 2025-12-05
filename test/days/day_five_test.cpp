#include "days/day_five.h"

#include <gtest/gtest.h>

using namespace aoc25::days;

TEST(DayFiveTest, PartOneExample)
{
    const std::string input{
        "3-5\n"
        "10-14\n"
        "16-20\n"
        "12-18\n"
        "\n"
        "1\n"
        "5\n"
        "8\n"
        "11\n"
        "17\n"
        "32"
    };

    const DayFive day_five{};
    EXPECT_EQ(day_five.partOne(input), "3");
}

TEST(DayFiveTest, PartTwoExample)
{
    const std::string input{
        "3-5\n"
        "10-14\n"
        "16-20\n"
        "12-18\n"
        "\n"
        "1\n"
        "5\n"
        "8\n"
        "11\n"
        "17\n"
        "32"
    };

    const DayFive day_five{};
    EXPECT_EQ(day_five.partTwo(input), "14");
}
