#include "days/day_three.h"

#include <gtest/gtest.h>

using namespace aoc25::days;

TEST(DayThreeTest, PartOneExample)
{
    const std::string input{
        "987654321111111\n"
        "811111111111119\n"
        "234234234234278\n"
        "818181911112111"
    };
    const DayThree day_three{};

    EXPECT_EQ(day_three.partOne(input), "357");
}

TEST(DayThreeTest, PartOneTrialOne)
{
    const std::string input{
        "4732321333332463233337712234322122322247222252423773321362313613333336333732233372323328332333322777"
        };
    const DayThree day_three{};

    EXPECT_EQ(day_three.partOne(input), "87");
}

TEST(DayThreeTest, PartOneTrialTwo)
{
    const std::string input{
        "12345"
        };
    const DayThree day_three{};

    EXPECT_EQ(day_three.partOne(input), "45");
}

TEST(DayThreeTest, PartOneTrialThree)
{
    const std::string input{
        "2776"
        };
    const DayThree day_three{};

    EXPECT_EQ(day_three.partOne(input), "77");
}

TEST(DayThreeTest, PartTwoExample)
{
    const std::string input{
        "987654321111111\n"
        "811111111111119\n"
        "234234234234278\n"
        "818181911112111"
    };
    const DayThree day_three{};

    EXPECT_EQ(day_three.partTwo(input), "3121910778619");
}

TEST(DayThreeTest, PartTwoTrialOne)
{
    const std::string input{
        "987654321111111"
    };
    const DayThree day_three{};

    EXPECT_EQ(day_three.partTwo(input), "987654321111");
}

TEST(DayThreeTest, PartTwoTrialTwo)
{
    const std::string input{
        "811111111111119"
    };
    const DayThree day_three{};

    EXPECT_EQ(day_three.partTwo(input), "811111111119");
}

TEST(DayThreeTest, PartTwoTrialThree)
{
    const std::string input{
        "234234234234278"
    };
    const DayThree day_three{};

    EXPECT_EQ(day_three.partTwo(input), "434234234278");
}

TEST(DayThreeTest, PartTwoTrialFour)
{
    const std::string input{
        "818181911112111"
    };
    const DayThree day_three{};

    EXPECT_EQ(day_three.partTwo(input), "888911112111");
}