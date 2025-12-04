#ifndef AOC25_DAY_THREE_H
#define AOC25_DAY_THREE_H
#include "abstract_day.h"

class DayThree final : public AbstractDay
{
public:
    [[nodiscard]] auto partOne(const std::string &input) const -> std::string override;

    [[nodiscard]] auto partTwo(const std::string &input) const -> std::string override;

private:
    long maxJoltage(const std::string &bank) const;
};

#endif //AOC25_DAY_THREE_H