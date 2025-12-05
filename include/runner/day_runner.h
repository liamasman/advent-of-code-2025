#ifndef AOC25_DAY_RUNNER_H
#define AOC25_DAY_RUNNER_H
#include <optional>
#include <string>

#include "RunResult.h"
#include "../abstract_day.h"

namespace aoc25
{
    class DayRunner
    {
    public:
        static auto run(const days::AbstractDay &day, int part, const std::optional<std::string> &
                        inputFilename) -> RunResult;
    };
}

#endif //AOC25_DAY_RUNNER_H