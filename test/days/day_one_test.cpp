#include "days/day_one.h"

#include <gtest/gtest.h>

TEST(DayRunnerTest, DayOneExample)
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
        "L82\n"
    };
    const DayOne day_one{};

    EXPECT_EQ(day_one.partOne(input), "3");
}