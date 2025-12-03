#ifndef AOC25_DAY_ONE_H
#define AOC25_DAY_ONE_H
#include "abstract_day.h"


class DayOne final : public AbstractDay
{
public:
    [[nodiscard]] auto partOne(const std::string &input) const -> std::string override;
    [[nodiscard]] auto partTwo(const std::string &input) const -> std::string override;
};


#endif //AOC25_DAY_ONE_H