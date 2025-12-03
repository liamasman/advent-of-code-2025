#include "day_runner.h"

#include <fstream>
#include <iostream>

std::string DayRunner::run(const AbstractDay& day, const int part, const std::optional<std::string>& inputFilename)
{
    const std::optional<std::string> input = inputFilename.has_value()
            ? std::optional{readFile(inputFilename.value())}
            : std::nullopt;

    if (part == 1)
    {
        return day.partOne(input);
    }
    else
    {
        return day.partTwo(input);
    }
}

std::string DayRunner::readFile(const std::string &filename)
{
    std::ifstream inputFile{filename};
    const auto contents = std::string{
        (std::istreambuf_iterator(inputFile)), std::istreambuf_iterator<char>()
    };
    inputFile.close();
    return contents;
}
