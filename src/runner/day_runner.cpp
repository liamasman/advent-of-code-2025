#include "runner/day_runner.h"
#include "utils/string_utils.h"

#include <chrono>

#include "runner/run_result.h"

namespace aoc25
{
    auto DayRunner::run(const days::AbstractDay& day, const int part, const std::optional<std::string>& inputFilename) -> RunResult
    {
        const auto start = std::chrono::high_resolution_clock::now();
        const std::string input = inputFilename.has_value()
                ? utils::readFile(inputFilename.value())
                : ""; //TODO if not passed a filename, read from stdin
        const auto readFinished = std::chrono::high_resolution_clock::now();
        std::string result{};
        if (part == 1)
        {
            result = day.partOne(input);
        }
        else
        {
            result = day.partTwo(input);
        }
        const auto finished = std::chrono::high_resolution_clock::now();
        return RunResult{
            result,
            std::chrono::duration_cast<std::chrono::microseconds>(readFinished - start),
            std::chrono::duration_cast<std::chrono::microseconds>(finished - readFinished)
        };
    }
}

