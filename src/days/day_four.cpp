#include "../include/days/day_four.h"

#include "utils/grid_utils.h"

constexpr auto ROLL = '@';

auto DayFour::partOne(const std::string &input) const -> std::string
{
    auto grid = parseGrid(input);
    const int height{static_cast<int>(grid.size())};
    const int width{static_cast<int>(grid[0].size())};
    int count{0};
    for (int x{0}; x < width; ++x)
    {
        for (int y{0}; y < height; ++y)
        {
            if (grid[y][x] == ROLL)
            {
                if (countNeighbours(grid, width, height, x, y) < 4)
                {
                    ++count;
                }
            }
        }
    }
    return std::to_string(count);
}

auto DayFour::partTwo(const std::string &input) const -> std::string
{
    return "To be implemented";
}

auto DayFour::countNeighbours(const std::vector<std::vector<char>> &grid,
    int width, int height,
    int x, int y) const -> int
{
    int count{0};
    if (x > 0 && grid[y][x - 1] == ROLL)
    {
        ++count;
    }
    if (x > 0 && y > 0 && grid[y - 1][x - 1] == ROLL)
    {
        ++count;
    }
    if (y > 0 && grid[y - 1][x] == ROLL)
    {
        ++count;
    }
    if (y > 0 && x < width - 1 && grid[y - 1][x + 1] == ROLL)
    {
        ++count;
    }
    if (x < width - 1 && grid[y][x + 1] == ROLL)
    {
        ++count;
    }
    if (x < width - 1 && y < height - 1 && grid[y + 1][x + 1] == ROLL)
    {
        ++count;
    }
    if (y < height - 1 && grid[y + 1][x] == ROLL)
    {
        ++count;
    }
    if (y < height - 1 && x > 0 && grid[y + 1][x - 1] == ROLL)
    {
        ++count;
    }
    return count;
}

