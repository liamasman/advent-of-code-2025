#ifndef AOC25_GRID_UTILS_H
#define AOC25_GRID_UTILS_H
#include <string>
#include <ranges>
#include <stdexcept>

#include "grid.h"
#include "string_utils.h"

inline auto parseGrid(const std::string &input) -> Grid
{
    int width{0};
    int height{0};

    // First pass: determine width and height (ignore empty lines and handle CRLF)
    for (auto &&line : getLines(input))
    {
        int len{0};
        for (const char ch : line)
        {
            if (ch == '\r') { continue; }
            ++len;
        }
        if (len == 0)
        {
            continue;
        }
        if (width == 0)
        {
            width = len;
        }
        else if (len != width)
        {
            throw std::runtime_error("parseGrid: inconsistent row width");
        }
        ++height;
    }

    std::string data;
    data.reserve(static_cast<std::size_t>(width) * static_cast<std::size_t>(height));

    // Second pass: fill data
    for (auto &&line : getLines(input))
    {
        int len{0};
        for (const char ch : line)
        {
            if (ch == '\r') { continue; }
            ++len;
        }
        if (len == 0)
        {
            continue;
        }
        for (const char ch : line)
        {
            if (ch == '\r') { continue; }
            data.push_back(ch);
        }
    }

    return Grid{data, width, height};
}

#endif //AOC25_GRID_UTILS_H