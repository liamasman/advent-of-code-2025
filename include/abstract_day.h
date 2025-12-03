#ifndef AOC25_ABSTRACT_DAY_H
#define AOC25_ABSTRACT_DAY_H
#include <string>

class AbstractDay
{
public:
    virtual ~AbstractDay() = default;

    [[nodiscard]] virtual std::string partOne(const std::optional<std::string>& input) const = 0;
    [[nodiscard]] virtual std::string partTwo(const std::optional<std::string>& input) const = 0;
};

#endif //AOC25_ABSTRACT_DAY_H