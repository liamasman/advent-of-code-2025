#ifndef AOC25_ABSTRACT_DAY_H
#define AOC25_ABSTRACT_DAY_H
#include <string>

class AbstractDay
{
public:
    virtual ~AbstractDay() = default;

    virtual const std::string partOne(const std::optional<std::string>& input) const;
    virtual const std::string partTwo(const std::optional<std::string>& input) const;
};

#endif //AOC25_ABSTRACT_DAY_H