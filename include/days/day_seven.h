#ifndef AOC25_DAY_SEVEN_H
#define AOC25_DAY_SEVEN_H

#include "abstract_day.h"

#include <vector>

namespace aoc25::days
{
    class DaySeven : public AbstractDay
    {
    public:
        [[nodiscard]] auto partOne(const std::string& input) const -> std::string override;

        [[nodiscard]] auto partTwo(const std::string& input) const -> std::string override;

    private:
        static void progressBeam(std::vector<std::string>& lines, size_t line, int& count);
    };
}

#endif //AOC25_DAY_SEVEN_H