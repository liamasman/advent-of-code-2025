#include "days/day_three.h"

#include <gtest/gtest.h>

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