//
// Created by liam on 03/12/2025.
//

#include "../../include/days/day_one.h"

#include <iostream>
#include <ranges>

std::string DayOne::partOne(const std::string& input) const
{
    int pointer{50};
    int count{0};
    for (const auto& line_range : std::views::split(input, '\n'))
    {
        if (line_range.empty())
        {
            continue;
        }
        const auto direction = line_range.front();
        const auto distance = std::stoi(std::string{line_range.begin() + 1, line_range.end()});

        if (direction == 'L')
        {
            pointer -= distance;
        }
        else
        {
            pointer += distance;
        }

        if (pointer < 0 || pointer > 99)
        {
            pointer %= 100;
        }

        if (pointer == 0)
        {
            ++count;
        }
    }

    return std::to_string(count);
}

std::string DayOne::partTwo(const std::string& input) const
{
    return "To be implemented.";
}