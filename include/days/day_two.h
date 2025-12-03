#ifndef AOC25_DAY_TWO_H
#define AOC25_DAY_TWO_H
#include "abstract_day.h"

class DayTwo final : public AbstractDay
{
public:
    [[nodiscard]] auto partOne(const std::string &input) const -> std::string override;
    [[nodiscard]] auto partTwo(const std::string &input) const -> std::string override;
private:
    static auto isValidIdPartOne(long id) -> bool;
    static auto isValidIdPartTwo(long id) -> bool;
};

#endif //AOC25_DAY_TWO_H