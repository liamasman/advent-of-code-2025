#ifndef AOC25_ABSTRACT_DAY_H
#define AOC25_ABSTRACT_DAY_H
#include <string>

namespace aoc25::days
{
    class AbstractDay
    {
    public:
        virtual ~AbstractDay() = default;

        [[nodiscard]] virtual auto partOne(const std::string& input) const -> std::string = 0;
        [[nodiscard]] virtual auto partTwo(const std::string& input) const -> std::string = 0;
    };
}

#endif //AOC25_ABSTRACT_DAY_H