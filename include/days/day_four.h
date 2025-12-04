#ifndef AOC25_DAY_FOUR_H
#define AOC25_DAY_FOUR_H

#include "abstract_day.h"
#include "utils/grid.h"

class DayFour final : public AbstractDay
{
public:
    [[nodiscard]] auto partOne(const std::string &input) const -> std::string override;
    [[nodiscard]] auto partTwo(const std::string &input) const -> std::string override;
private:
    auto countNeighbours(const Grid &grid, int x, int y) const -> int;
};

#endif //AOC25_DAY_FOUR_H