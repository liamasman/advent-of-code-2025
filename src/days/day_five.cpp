#include "days/day_five.h"

#include "utils/string_utils.h"

namespace aoc25::days
{
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

    auto DayFive::partTwo(const std::string &input) const -> std::string
    {
        const auto parsedInput = parseInput(input);

        long count{0};
        for (const auto &range : parsedInput.ranges())
        {
            const auto size = range.end() - range.start() + 1;
            count += size;
        }
        return std::to_string(count);
    }

    auto constexpr DayFive::Range::isInRange(const long value) const -> bool
    {
        return value >= _start && value <= _end;
    }

    auto DayFive::parseRange(const std::string_view &range) -> Range
    {
        const auto &[start, end] = utils::getPair(range, '-');
        return Range{std::stol(start), std::stol(end)};
    }

    auto DayFive::parseInput(const std::string_view &input) -> ParsedInput
    {
        auto lines = utils::getLines(input);

        std::vector<Range> ranges;
        std::vector<long> ids;

        auto iterator = lines.begin();
        for (; !(*iterator).empty(); ++iterator)
        {
            const auto range = parseRange({(*iterator).begin(), (*iterator).end()});
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

    auto DayFive::ParsedInput::sortAndCombine(const std::vector<Range> &ranges) -> std::vector<Range>
    {
        auto sorted = ranges;
        std::ranges::sort(sorted.begin(), sorted.end(), [](const auto &lhs, const auto &rhs) { return lhs.start() < rhs.start(); });

        std::vector<Range> merged;
        for (const auto &range : sorted)
        {
            if (merged.empty())
            {
                merged.emplace_back(range);
                continue;
            }

            const auto &last = merged.back();
            if (last.end() >= range.start())
            {
                const Range mergedRange{last.start(), std::max(last.end(), range.end())};
                merged.pop_back();
                merged.emplace_back(mergedRange);
            }
            else
            {
                merged.emplace_back(range);
            }
        }
        return merged;
    }
}
