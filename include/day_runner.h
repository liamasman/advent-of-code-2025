#ifndef AOC25_DAY_RUNNER_H
#define AOC25_DAY_RUNNER_H
#include <optional>
#include <string>

#include "abstract_day.h"


class DayRunner
{
public:
    static auto run(const AbstractDay& day, int part, const std::optional<std::string>& inputFilename) -> std::string;
};


#endif //AOC25_DAY_RUNNER_H