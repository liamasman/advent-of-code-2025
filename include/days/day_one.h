#ifndef AOC25_DAY_ONE_H
#define AOC25_DAY_ONE_H
#include "abstract_day.h"


class DayOne final : public AbstractDay
{
public:
    [[nodiscard]] std::string partOne(const std::string &input) const override;
    [[nodiscard]] std::string partTwo(const std::string &input) const override;
};


#endif //AOC25_DAY_ONE_H