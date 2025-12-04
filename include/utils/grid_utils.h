#ifndef AOC25_GRID_UTILS_H
#define AOC25_GRID_UTILS_H
#include <string>
#include <vector>

#include "string_utils.h"

inline auto parseGrid(const std::string &input) -> std::vector<std::vector<char>>
{
    std::vector<std::vector<char>> grid{};
    for (const auto &line : getLines(input))
    {
        if (line.empty())
        {
            continue;
        }
        std::vector<char> row{};
        for (const auto &c : line)
        {
            row.emplace_back(c);
        }
        grid.emplace_back(row);
    }
    return grid;
}

#endif //AOC25_GRID_UTILS_H
