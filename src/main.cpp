#include <iostream>
#include <memory>
#include <vector>

#include "day_runner.h"
#include "days/day_one.h"
#include "days/day_two.h"

void printUsage(const char* programName)
{
    std::cout << "Usage: " << programName << " day part [filename]\n";
}

auto generateDays() -> std::vector<std::unique_ptr<AbstractDay>>
{
    auto vector = std::vector<std::unique_ptr<AbstractDay>>{};
    vector.emplace_back(std::make_unique<DayOne>());
    vector.emplace_back(std::make_unique<DayTwo>());
    return vector;
}

auto main(const int argc, const char *argv[]) -> int
{
    const auto days = generateDays();

    if (argc < 3)
    {
        printUsage(argv[0]);
        return 1;
    }

    const int day{std::stoi(argv[1])};
    if (day <= 0 || day > 12)
    {
        printUsage(argv[0]);
        return 1;
    }

    const int part{std::stoi(argv[2])};
    if (part <= 0 || part > 2)
    {
        printUsage(argv[0]);
        return 1;
    }


    const std::optional<std::string> input = (argc >= 4)
        ? std::optional{std::string{argv[3]}}
        : std::nullopt;

    std::cout << DayRunner::run(*days[day-1], part, input) << '\n';
}
