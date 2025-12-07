#include "days/day_seven.h"

#include <gtest/gtest.h>

using namespace aoc25::days;

TEST(DaySevenTest, PartOneExample)
{
    const std::string input{
        ".......S.......\n"
        "...............\n"
        ".......^.......\n"
        "...............\n"
        "......^.^......\n"
        "...............\n"
        ".....^.^.^.....\n"
        "...............\n"
        "....^.^...^....\n"
        "...............\n"
        "...^.^...^.^...\n"
        "...............\n"
        "..^...^.....^..\n"
        "...............\n"
        ".^.^.^.^.^...^.\n"
        "..............."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "21");
}

TEST(DaySevenTest, PartOneSingleS)
{
    const std::string input{
        "...S...\n"
        "......."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "0");
}

TEST(DaySevenTest, PartOneSingleSplit)
{
    const std::string input{
        "...S...\n"
          ".......\n"
          "...^...\n"
          "......."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "1");
}

TEST(DaySevenTest, PartOneTwoSplitsToMakeThreeBeams)
{
    const std::string input{
        "...S...\n"
        ".......\n"
        "...^...\n"
        ".......\n"
        "..^.^..\n"
        "......."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "3");
}

TEST(DaySevenTest, PartOneWhereOneSplitterDoesNothing)
{
    const std::string input{
        "...S...\n"
        ".......\n"
        "...^...\n"
        ".......\n"
        "..^.^..\n"
        ".......\n"
        ".^.^.^.\n"
        "......."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "6");
}

TEST(DaySevenTest, PartOneWithALineOfSplitters)
{
    const std::string input{
        "....S....\n"
        ".........\n"
        "....^....\n"
        ".........\n"
        "...^.^...\n"
        ".........\n"
        "..^...^..\n"
        ".........\n"
        ".^.^.^.^.\n"
        "........."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "9");
}

TEST(DaySevenTest, PartOneWithASplitterDirectlyBelowAnother)
{
    const std::string input{
        "...S...\n"
        ".......\n"
        "...^...\n"
        ".......\n"
        "...^...\n"
        "......."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "1");
}

TEST(DaySevenTest, PartOneWithASplitterTwoBelowAnother)
{
    const std::string input{
        "...S...\n"
        ".......\n"
        "...^...\n"
        ".......\n"
        ".......\n"
        ".......\n"
        "...^...\n"
        "......."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "1");
}

TEST(DaySevenTest, PartOneWithASplitterTwoBelowAnotherButBeingFedByAnother)
{
    const std::string input{
        "...S...\n"
        ".......\n"
        "...^...\n"
        ".......\n"
        "..^....\n"
        ".......\n"
        "...^...\n"
        "......."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "3");
}

TEST(DaySevenTest, PartOneWithASplitterOnlyBeingFedByAnInactiveSplitter)
{
    const std::string input{
        ".S....\n"
        ".......\n"
        ".^.^...\n"
        ".......\n"
        "......\n"
        ".......\n"
        "....^..\n"
        "......."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partOne(input), "1");
}

TEST(DaySevenTest, PartTwoExample)
{
    const std::string input{
        ".......S.......\n"
        "...............\n"
        ".......^.......\n"
        "...............\n"
        "......^.^......\n"
        "...............\n"
        ".....^.^.^.....\n"
        "...............\n"
        "....^.^...^....\n"
        "...............\n"
        "...^.^...^.^...\n"
        "...............\n"
        "..^...^.....^..\n"
        "...............\n"
        ".^.^.^.^.^...^.\n"
        "..............."
    };

    const DaySeven day_seven{};

    EXPECT_EQ(day_seven.partTwo(input), "40");
}