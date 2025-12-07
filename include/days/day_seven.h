#ifndef AOC25_DAY_SEVEN_H
#define AOC25_DAY_SEVEN_H

#include "abstract_day.h"

#include <vector>

namespace aoc25::days
{
    class DaySeven : public AbstractDay
    {
    public:
        [[nodiscard]] auto partOne(const std::string& input) const -> std::string override;

        [[nodiscard]] auto partTwo(const std::string& input) const -> std::string override;

    private:
        static void progressBeamPartOne(std::vector<std::string>& lines, size_t lineIndex, int& count);

        static auto progressBeamPartTwo(std::vector<std::string> &lines, size_t lineIndex,
                                 const std::vector<long> &pathsAtLine) -> std::vector<long>;
    };
}

#endif //AOC25_DAY_SEVEN_H