#ifndef AOC25_DAY_NINE_H
#define AOC25_DAY_NINE_H
#include <vector>

#include "abstract_day.h"

namespace aoc25::days
{
    class DayNine : public AbstractDay
    {
    public:
        [[nodiscard]] auto partOne(
            const std::string &input) const -> std::string override;

        [[nodiscard]] auto partTwo(
            const std::string &input) const -> std::string override;

    private:
        [[nodiscard]] static auto getPointsList(
            const std::string &input) -> std::vector<std::pair<int, int>>;
    };
}

#endif //AOC25_DAY_NINE_H
