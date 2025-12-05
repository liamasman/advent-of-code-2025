#include "days/day_one.h"

#include <gtest/gtest.h>

using namespace aoc25::days;

TEST(DayOneTest, PartOneExample)
{
    const std::string input{
        "L68\n"
        "L30\n"
        "R48\n"
        "L5\n"
        "R60\n"
        "L55\n"
        "L1\n"
        "L99\n"
        "R14\n"
        "L82"
    };
    const DayOne day_one{};

    EXPECT_EQ(day_one.partOne(input), "3");
}
TEST(DayOneTest, PartTwoExample)
{
    const std::string input{
        "L68\n"
        "L30\n"
        "R48\n"
        "L5\n"
        "R60\n"
        "L55\n"
        "L1\n"
        "L99\n"
        "R14\n"
        "L82"
    };
    const DayOne day_one{};

    EXPECT_EQ(day_one.partTwo(input), "6");
}