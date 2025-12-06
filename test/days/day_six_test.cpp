#include "days/day_six.h"

#include <gtest/gtest.h>

using namespace aoc25::days;

TEST(DaySixTest, PartOneExample)
{
    const std::string input{
        "123 328  51 64 \n"
     "45 64  387 23 \n"
      "6 98  215 314\n"
    "*   +   *   +  "
    };
    const DaySix day_six{};
    EXPECT_EQ(day_six.partOne(input), "4277556");
}

TEST(DaySixTest, PartTwoExample)
{
    const std::string input{
        "123 328  51 64 \n"
        " 45 64  387 23 \n"
        "  6 98  215 314\n"
    "*   +   *   +  "
    };
    const DaySix day_six{};
    EXPECT_EQ(day_six.partTwo(input), "3263827");
}