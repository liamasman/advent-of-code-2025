#include "../include/days/day_three.h"

#include <assert.h>

#include "utils/string_utils.h"

auto DayThree::partOne(const std::string &input) const -> std::string
{
    long total{0};
    for (const auto &line : getLines(input))
    {
        if (line.empty())
        {
            continue;
        }
        total += maxJoltage(std::string{line.begin(), line.end()});
    }
    return std::to_string(total);
}

auto DayThree::partTwo(const std::string &input) const -> std::string
{
    return "To be implemented";
}

auto DayThree::maxJoltage(const std::string &bank) const -> long
{
    int a{static_cast<int>(bank.length() - 2)};
    int b{static_cast<int>(bank.length() - 1)};

    int max1{bank[a] - '0'};
    int max2{bank[b] - '0'};

#ifndef NDEBUG
    int currentMax{10 * max1 + max2};
#endif // NDEBUG

    while (a >= 0)
    {
        a--;
        if (bank[a] - '0' >= max1)
        {
            if (max1 > max2)
            {
                max2 = max1;
            }
            max1 = bank[a] - '0';
#ifndef NDEBUG
            int newMax{10 * max1 + max2};
            assert(newMax >= currentMax);
            currentMax = newMax;
#endif // NDEBUG
        }
    }
    return 10 * max1 + max2;
}
