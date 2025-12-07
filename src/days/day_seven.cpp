#include "days/day_seven.h"

#include <numeric>
#include <vector>

#include "utils/string_utils.h"

namespace aoc25::days
{
    constexpr auto START = 'S';
    constexpr auto BEAM = '|';
    constexpr auto SPLITTER = '^';
    constexpr auto EMPTY = '.';

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
            progressBeamPartOne(lines, i, count);
        }

        return std::to_string(count);
    }

    auto DaySeven::partTwo(const std::string &input) const -> std::string
    {
        std::vector<std::string> lines;
        for (const auto& line : utils::getLines(input))
        {
            lines.emplace_back(line.begin(), line.end());
        }

        const size_t indexOfStart{lines[0].find(START)};
        lines[1][indexOfStart] = BEAM;

        std::vector pathsToLine(lines[0].size(), 0L);
        pathsToLine[indexOfStart] = 1;
        for (size_t i{2}; i < lines.size(); ++i)
        {
            pathsToLine = progressBeamPartTwo(lines, i, pathsToLine);
        }

        return std::to_string(std::accumulate(pathsToLine.begin(), pathsToLine.end(), 0L));
    }

    void DaySeven::progressBeamPartOne(std::vector<std::string> &lines, const size_t lineIndex,
        int &count)
    {
        const auto previousLine = lines[lineIndex-1];
        auto &lineToProgress = lines[lineIndex];
        for (size_t i{0}; i < lineToProgress.size(); ++i)
        {
            if (previousLine[i] != BEAM)
            {
                if (lineToProgress[i] == SPLITTER)
                {
                    lineToProgress[i] = EMPTY;
                }
                continue;
            }

            if (lineToProgress[i] == SPLITTER)
            {
                ++count;
                lineToProgress[i - 1] = BEAM;
                lineToProgress[i + 1] = BEAM;
            }
            else
            {
                lineToProgress[i] = BEAM;
            }
        }
    }

    auto DaySeven::progressBeamPartTwo(std::vector<std::string> &lines,
        const size_t lineIndex, const std::vector<long> &pathsToPreviousLine) -> std::vector<long>
    {
        const auto previousLine = lines[lineIndex-1];
        auto &lineToProgress = lines[lineIndex];
        std::vector<long> pathsToLine;
        pathsToLine.reserve(pathsToPreviousLine.size());
        for (size_t i{0}; i < lineToProgress.size(); ++i)
        {
            if (previousLine[i] != BEAM)
            {
                if (lineToProgress[i] == SPLITTER)
                {
                    lineToProgress[i] = EMPTY;
                }
                continue;
            }

            if (lineToProgress[i] == SPLITTER)
            {
                lineToProgress[i - 1] = BEAM;
                lineToProgress[i + 1] = BEAM;
            }
            else
            {
                lineToProgress[i] = BEAM;
            }
        }

        for (size_t i{0}; i < lineToProgress.size(); ++i)
        {
            if (lineToProgress[i] == BEAM)
            {
                long ways{0};
                if (i > 0 && lineToProgress[i - 1] == SPLITTER)
                {
                    ways += pathsToPreviousLine[i - 1];
                }
                if (i < lineToProgress.size() - 1 && lineToProgress[i + 1] == SPLITTER)
                {
                    ways += pathsToPreviousLine[i + 1];
                }
                if (previousLine[i] == BEAM)
                {
                    ways += pathsToPreviousLine[i];
                }
                pathsToLine.push_back(ways);
            }
            else
            {
                pathsToLine.push_back(0);
            }
        }
        return pathsToLine;
    }
}
