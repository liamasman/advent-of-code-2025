#include "days/day_two.h"

#include <gtest/gtest.h>

using namespace aoc25::days;

TEST(DayTwoTest, PartOneExample)
{
    const std::string input{"11-22,95-115,998-1012,1188511880-1188511890,222220-222224,"
        "1698522-1698528,446443-446449,38593856-38593862,565653-565659,"
        "824824821-824824827,2121212118-2121212124"
    };
    const DayTwo day_two{};

    EXPECT_EQ(day_two.partOne(input), "1227775554");
}

TEST(DayTwoTest, PartTwoExample)
{
    const std::string input{"11-22,95-115,998-1012,1188511880-1188511890,222220-222224,"
        "1698522-1698528,446443-446449,38593856-38593862,565653-565659,"
        "824824821-824824827,2121212118-2121212124"
    };
    const DayTwo day_two{};

    EXPECT_EQ(day_two.partTwo(input), "4174379265");
}