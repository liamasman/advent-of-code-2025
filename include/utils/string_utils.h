#ifndef AOC25_STRING_UTILS_H
#define AOC25_STRING_UTILS_H
#include <ranges>
#include <string>

inline auto getLines(const std::string &input)
{
    return std::views::split(input, '\n');
}

#endif //AOC25_STRING_UTILS_H