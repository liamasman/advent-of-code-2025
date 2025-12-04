#ifndef AOC25_GRID_UTILS_H
#define AOC25_GRID_UTILS_H
#include <string>

#include "grid.h"
#include "string_utils.h"

inline auto parseGrid(const std::string &input) -> Grid
{
    std::ostringstream ss{};
    int width{0};
    int height{0};
    for (const auto &line : getLines(input))
    {
        if (line.empty())
        {
            continue;
        }
        ss << std::string{line.begin(), line.end()};
        width = line.size();
        ++height;
    }
    return Grid{ss.str(), width, height};
}

#endif //AOC25_GRID_UTILS_H