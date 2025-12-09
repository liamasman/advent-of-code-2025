#include "days/day_nine.h"

#include "utils/string_utils.h"

namespace aoc25::days
{
    auto DayNine::getPointsList(
        const std::string &input) -> std::vector<std::pair<int, int> >
    {
        std::vector<std::pair<int, int> > points;
        for (const auto &line: utils::getLines(input))
        {
            const auto &[xString, yString] = utils::getPair(
                {line.begin(), line.end()}, ',');
            const int x = std::stoi(xString);
            const int y = std::stoi(yString);
            points.emplace_back(x, y);
        }

        return points;
    }

    auto DayNine::partOne(const std::string &input) const -> std::string
    {
        const auto points{getPointsList(input)};

        long maxArea{0};

        for (int i{0}; i < points.size(); ++i)
        {
            const auto [x1, y1] = points[i];
            for (int j{i + 1}; j < points.size(); ++j)
            {
                const auto [x2, y2] = points[j];

                long area{static_cast<long>(std::abs(x1 - x2 + 1)) * static_cast<long>(std::abs(y1 - y2 + 1))};
                if (area > maxArea)
                {
                    maxArea = area;
                }
            }
        }

        return std::to_string(maxArea);
    }

    auto DayNine::partTwo(const std::string &input) const -> std::string
    {
        return "To be implemented.";
    }
}
