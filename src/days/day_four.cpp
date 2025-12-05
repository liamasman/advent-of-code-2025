#include "days/day_four.h"
#include "utils/grid_utils.h"

namespace aoc25::days
{
    constexpr auto ROLL = '@';

    auto DayFour::partOne(const std::string &input) const -> std::string
    {
        auto grid = utils::parseGrid(input);
        int count{0};
        for (int x{0}; x < grid.width(); ++x)
        {
            for (int y{0}; y < grid.height(); ++y)
            {
                if (grid.getCell(x, y) == ROLL)
                {
                    if (countNeighbours(grid, x, y) < 4)
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
        auto grid = utils::parseGrid(input);
        int totalRemoved{0};
        for (;;)
        {
            bool removed = false;
            for (int x{0}; x < grid.width(); ++x)
            {
                for (int y{0}; y < grid.height(); ++y)
                {
                    if (grid.getCell(x, y) == ROLL)
                    {
                        if (countNeighbours(grid, x, y) < 4)
                        {
                            grid.setCell(x, y, '.');
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
        }
        return std::to_string(totalRemoved);
    }

    auto DayFour::countNeighbours(const utils::Grid<char> &grid,
        int x, int y) -> int
    {
        int count{0};
        for (const auto& neighbour : grid.getNeighbours(x, y))
        {
            if (neighbour == ROLL)
            {
                ++count;
            }
        }
        return count;
    }
}
