#include "../include/day_runner.h"
#include "../include/utils/string_utils.h"

auto DayRunner::run(const AbstractDay& day, const int part, const std::optional<std::string>& inputFilename) -> std::string
{
    const std::string input = inputFilename.has_value()
            ? readFile(inputFilename.value())
            : ""; //TODO if not passed a filename, read from stdin

    if (part == 1)
    {
        return day.partOne(input);
    }
    else
    {
        return day.partTwo(input);
    }
}


