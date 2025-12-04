#include "utils/grid.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(GridTest, CanGetCellContents)
{
    const std::string input{
        "12345"
        "67890"
        "abcde"
        "fghij"
    };
    const Grid grid{input, 5, 4};
    EXPECT_EQ('1', grid.getCell(0, 0));
    EXPECT_EQ('2', grid.getCell(1, 0));
    EXPECT_EQ('3', grid.getCell(2, 0));
    EXPECT_EQ('4', grid.getCell(3, 0));
    EXPECT_EQ('5', grid.getCell(4, 0));
    EXPECT_EQ('6', grid.getCell(0, 1));
    EXPECT_EQ('7', grid.getCell(1, 1));
    EXPECT_EQ('8', grid.getCell(2, 1));
    EXPECT_EQ('9', grid.getCell(3, 1));
    EXPECT_EQ('0', grid.getCell(4, 1));
    EXPECT_EQ('a', grid.getCell(0, 2));
    EXPECT_EQ('b', grid.getCell(1, 2));
    EXPECT_EQ('c', grid.getCell(2, 2));
    EXPECT_EQ('d', grid.getCell(3, 2));
    EXPECT_EQ('e', grid.getCell(4, 2));
    EXPECT_EQ('f', grid.getCell(0, 3));
    EXPECT_EQ('g', grid.getCell(1, 3));
    EXPECT_EQ('h', grid.getCell(2, 3));
    EXPECT_EQ('i', grid.getCell(3, 3));
    EXPECT_EQ('j', grid.getCell(4, 3));
}

TEST(GridTest, CanGetNeighbours)
{
    const std::string input{
        "12345"
        "67890"
        "abcde"
        "fghij"
    };
    const Grid grid{input, 5, 4};
    const auto neighbours = grid.getNeighbours(0, 0);
    EXPECT_THAT(neighbours, ::testing::UnorderedElementsAre(
        '2',
        '6',
        '7'
    ));
}

