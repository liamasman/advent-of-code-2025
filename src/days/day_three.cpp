#include "days/day_three.h"
#include "utils/string_utils.h"

#include <cassert>
#include <cmath>
#include <vector>


auto DayThree::partOne(const std::string &input) const -> std::string
{
    long total{0};
    for (const auto &line : getLines(input))
    {
        if (line.empty())
        {
            continue;
        }
        total += maxJoltagePartOne(std::string{line.begin(), line.end()});
    }
    return std::to_string(total);
}

auto DayThree::partTwo(const std::string &input) const -> std::string
{
    long total{0};
    for (const auto &line : getLines(input))
    {
        if (line.empty())
        {
            continue;
        }
        total += maxJoltagePartTwo(std::string{line.begin(), line.end()});
    }
    return std::to_string(total);
}

auto DayThree::maxJoltagePartOne(const std::string &bank) const -> long
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

auto DayThree::maxJoltagePartTwo(const std::string &bank) const -> long
{
    // maxJoltages[n][m] = maxJoltage for n batteries from the last m batteries of the bank
    std::vector maxJoltages(13, std::vector(bank.length() + 1, 0L));

    for (int numBatteries{1}; numBatteries <= 12; ++numBatteries)
    {
        for (int batteriesInBank{numBatteries}; batteriesInBank <= bank.length(); ++batteriesInBank)
        {
            maxJoltages[numBatteries][batteriesInBank] = std::max(
                (bank[bank.length() - batteriesInBank] - '0') * static_cast<long>(std::pow(10, numBatteries - 1)) + maxJoltages[numBatteries - 1][batteriesInBank-1],
                maxJoltages[numBatteries][batteriesInBank - 1]
            );
        }
    }

    return maxJoltages[12][bank.length()];
}
