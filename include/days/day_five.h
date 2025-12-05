#ifndef AOC25_DAY_FIVE_H
#define AOC25_DAY_FIVE_H
#include <vector>

#include "abstract_day.h"

namespace aoc25::days
{
    class DayFive : public AbstractDay
    {
    public:
        [[nodiscard]] auto partOne(const std::string &input) const -> std::string override;
        [[nodiscard]] auto partTwo(const std::string &input) const -> std::string override;
    private:
        class Range
        {
        private:
            long _start;
            long _end;
        public:
            Range(const long start, const long end) : _start{start}, _end{end}
            {}

            [[nodiscard]] auto isInRange(long value) const -> bool;
        };

        class ParsedInput
        {
        private:
            const std::vector<Range> _ranges;
            const std::vector<long> _ids;
        public:
            ParsedInput(const std::vector<Range>& range, const std::vector<long>& ids) : _ranges{range}, _ids{ids}
            {}

            [[nodiscard]] auto ids() const -> const std::vector<long>&;
            [[nodiscard]] auto ranges() const -> const std::vector<Range>&;
        };

        [[nodiscard]] static auto parseRange(const std::string &range) -> Range;
        [[nodiscard]] static auto parseInput(const std::string &input) -> ParsedInput;
    };
}

#endif //AOC25_DAY_FIVE_H
