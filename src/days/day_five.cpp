#include "days/day_five.h"

#include "utils/string_utils.h"

namespace aoc25::days
{
    /* Potential to optimize by sorting ranges, then doing a binary search on
     * the ranges to find one that fits
     */
    auto DayFive::partOne(const std::string &input) const -> std::string
    {
        const auto parsedInput = parseInput(input);

        int count{0};
        for (const auto &id: parsedInput.ids())
        {
            for (const auto &range: parsedInput.ranges())
            {
                if (range.isInRange(id))
                {
                    ++count;
                    break;
                }
            }
        }

        return std::to_string(count);
    }

    auto DayFive::ParsedInput::ids() const -> const std::vector<long> &
    {
        return _ids;
    }

    auto DayFive::ParsedInput::ranges() const -> const std::vector<Range> &
    {
        return _ranges;
    }

    auto DayFive::partTwo(const std::string &input) const -> std::string
    {
        return "To be implemented";
    }

    auto DayFive::Range::isInRange(long value) const -> bool
    {
        return value >= _start && value <= _end;
    }

    auto DayFive::parseRange(const std::string &range) -> Range
    {
        const auto &[start, end] = utils::getPair(range, '-');
        return Range{std::stol(start), std::stol(end)};
    }

    auto DayFive::parseInput(const std::string &input) -> ParsedInput
    {
        auto lines = utils::getLines(input);

        std::vector<Range> ranges;
        std::vector<long> ids;

        auto iterator = lines.begin();
        for (; !(*iterator).empty(); ++iterator)
        {
            const std::string line((*iterator).begin(), (*iterator).end());
            const auto range = parseRange(line);
            ranges.push_back(range);
        }

        ++iterator; //Skip empty line

        for (; iterator != lines.end(); ++iterator)
        {
            const std::string line((*iterator).begin(), (*iterator).end());
            ids.push_back(std::stol(line));
        }

        return ParsedInput{ranges, ids};
    }
}
