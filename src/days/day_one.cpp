//
// Created by liam on 03/12/2025.
//

#include "../../include/days/day_one.h"

#include <iostream>
#include <ranges>

auto DayOne::partOne(const std::string& input) const -> std::string
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

auto DayOne::partTwo(const std::string& input) const -> std::string
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

        const auto travel = (direction == 'L') ? -distance : distance;

        const auto remainder = abs(travel) % 100;
        const auto completeRotations = abs(travel) / 100;

        if (pointer != 0 && remainder != 0)
        {
            if (travel < 0 && pointer - remainder <= 0)
            {
                ++count;
            }
            else if (travel > 0 && pointer + remainder >= 100)
            {
                ++count;
            }
        }

        count += completeRotations;

        pointer += travel % 100;
        pointer = (pointer + 100) % 100;
    }

    return std::to_string(count);
}