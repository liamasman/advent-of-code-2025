#ifndef AOC25_DAY_THREE_H
#define AOC25_DAY_THREE_H
#include "abstract_day.h"

namespace aoc25::days
{
    class DayThree final : public AbstractDay
    {
    public:
        [[nodiscard]] auto partOne(const std::string &input) const -> std::string override;

        [[nodiscard]] auto partTwo(const std::string &input) const -> std::string override;

    private:
        static long maxJoltagePartOne(const std::string &bank);
        static long maxJoltagePartTwo(const std::string &bank);
    };
}

#endif //AOC25_DAY_THREE_H