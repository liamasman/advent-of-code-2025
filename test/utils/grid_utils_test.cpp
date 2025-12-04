#include "utils/grid_utils.h"
#include "utils/grid.h"

#include <gtest/gtest.h>

TEST(ParseGridTest, CanParseGrid)
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
    const auto grid = parseGrid(input);
    const Grid<char> expected{
        "..@@.@@@@."
        "@@@.@.@.@@"
        "@@@@@.@.@@"
        "@.@@@@..@."
        "@@.@@@@.@@"
        ".@@@@@@@.@"
        ".@.@.@.@@@"
        "@.@@@.@@@@"
        ".@@@@@@@@."
        "@.@.@@@.@.",
        10, 10
    };
    EXPECT_EQ(grid, expected);
}

TEST(ParseGridTest, NewLineAtEndIsIgnored)
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
        "@.@.@@@.@.\n"
    };
    const auto grid = parseGrid(input);
    const Grid<char> expected{
        "..@@.@@@@."
        "@@@.@.@.@@"
        "@@@@@.@.@@"
        "@.@@@@..@."
        "@@.@@@@.@@"
        ".@@@@@@@.@"
        ".@.@.@.@@@"
        "@.@@@.@@@@"
        ".@@@@@@@@."
        "@.@.@@@.@.",
        10, 10
    };
    EXPECT_EQ(grid, expected);
}