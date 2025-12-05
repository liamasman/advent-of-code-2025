#ifndef AOC25_RUN_RESULT_H
#define AOC25_RUN_RESULT_H
#include <chrono>
#include <string>

namespace aoc25
{
    struct RunResult
    {
        std::string result;
        std::chrono::microseconds fileReadDuration;
        std::chrono::microseconds runDuration;

    };
}
#endif //AOC25_RUN_RESULT_H