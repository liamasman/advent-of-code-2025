#include "days/day_four.h"

#include <gtest/gtest.h>

TEST(DayFourTest, PartOneExample)
{
    const std::string input{
        "..@@.@@@@.\n"
        "@@@.@.@.@@\n"
        "@@@@@.@.@@\n"
        "@.@@@@..@.\n"
        "@@.@@@@.@@\n"
        ".@@@@@@@.@\n"
        ".@.@.@.@@@\n"
        "@.@@@.@@@@\n"
        ".@@@@@@@@.\n"
        "@.@.@@@.@."
    };
    const DayFour day_four{};

    EXPECT_EQ(day_four.partOne(input), "13");
}
