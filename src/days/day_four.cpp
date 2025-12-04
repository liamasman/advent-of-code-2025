#include "../include/days/day_four.h"

#include "utils/grid_utils.h"
#include <array>

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
    auto grid = parseGrid(input);
    const int height{static_cast<int>(grid.size())};
    const int width{static_cast<int>(grid[0].size())};
    int totalRemoved{0};
    for (;;)
    {
        bool removed = false;
        auto gridCopy{grid};
        for (int x{0}; x < width; ++x)
        {
            for (int y{0}; y < height; ++y)
            {
                if (grid[y][x] == ROLL)
                {
                    if (countNeighbours(grid, width, height, x, y) < 4)
                    {
                        gridCopy[y][x] = '.';
                        ++totalRemoved;
                        removed = true;
                    }
                }
            }
        }
        if (!removed)
        {
            break;
        }
        grid = std::move(gridCopy);
    }
    return std::to_string(totalRemoved);
}

auto DayFour::countNeighbours(const std::vector<std::vector<char>> &grid,
    int width, int height,
    int x, int y) const -> int
{
    constexpr std::array<std::pair<int, int>, 8> directions = {{{-1, 0},
                                                                {-1, -1},
                                                                {0, -1},
                                                                {1, -1},
                                                                {1, 0},
                                                                {1, 1},
                                                                {0, 1},
                                                                {-1, 1}}};

    int count{0};
    for (const auto& [dx, dy] : directions)
    {
        const int newX = x + dx;
        const int newY = y + dy;

        if (newX >= 0 && newX < width && newY >= 0 && newY < height && grid[newY][newX] == ROLL)
        {
            ++count;
        }
    }
    return count;
}
