#ifndef AOC25_DAY_SIX_H
#define AOC25_DAY_SIX_H
#include "abstract_day.h"

namespace aoc25::days
{
    class DaySix : public AbstractDay
    {
    private:

    public:
        [[nodiscard]] auto partOne(const std::string &input) const -> std::string override;
        [[nodiscard]] auto partTwo(const std::string &input) const -> std::string override;
    };
}

#endif //AOC25_DAY_SIX_H
