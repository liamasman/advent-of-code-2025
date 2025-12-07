#include "days/day_seven.h"

#include <vector>

#include "utils/string_utils.h"

namespace aoc25::days
{
    constexpr auto START = 'S';
    constexpr auto BEAM = '|';
    constexpr auto SPLITTER = '^';
    constexpr auto ACTIVE_SPLITTER = 'V';

    auto DaySeven::partOne(const std::string &input) const -> std::string
    {
        std::vector<std::string> lines;
        for (const auto& line : utils::getLines(input))
        {
            lines.emplace_back(line.begin(), line.end());
        }

        const size_t indexOfStart{lines[0].find(START)};
        lines[1][indexOfStart] = BEAM;

        int count{0};
        for (size_t i{2}; i < lines.size(); ++i)
        {
            progressBeam(lines, i, count);
        }

        return std::to_string(count);
    }

    auto DaySeven::partTwo(const std::string &input) const -> std::string
    {
        return "To Be Implemented";
    }

    void DaySeven::progressBeam(std::vector<std::string> &lines, const size_t line,
        int &count)
    {
        const auto previousLine = lines[line-1];
        auto &lineToProgress = lines[line];
        for (size_t i{0}; i < lineToProgress.size(); ++i)
        {
            if (previousLine[i] != BEAM)
            {
                continue;
            }

            if (lineToProgress[i] == SPLITTER)
            {
                ++count;
                lineToProgress[i - 1] = BEAM;
                lineToProgress[i] = ACTIVE_SPLITTER;
                lineToProgress[i + 1] = BEAM;
            }
            else
            {
                lineToProgress[i] = BEAM;
            }
        }
    }
}
