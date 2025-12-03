#ifndef AOC25_DAY_RUNNER_H
#define AOC25_DAY_RUNNER_H
#include <optional>
#include <string>

#include "abstract_day.h"


class DayRunner
{
public:
    static std::string run(const AbstractDay& day, const int part, const std::optional<std::string>& inputFilename);

private:
    static std::string readFile(const std::string& filename);
};


#endif //AOC25_DAY_RUNNER_H