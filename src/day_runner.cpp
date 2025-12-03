#include "../include/day_runner.h"

#include <fstream>
#include <iostream>

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

auto DayRunner::readFile(const std::string &filename) -> std::string
{
    //TODO exception if file does not exist
    std::ifstream inputFile{filename};
    const auto contents = std::string{
        (std::istreambuf_iterator(inputFile)), std::istreambuf_iterator<char>()
    };
    inputFile.close();
    return contents;
}
