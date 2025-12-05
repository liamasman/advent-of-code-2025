#ifndef AOC25_DAY_FIVE_H
#define AOC25_DAY_FIVE_H
#include <algorithm>
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

            [[nodiscard]] auto constexpr isInRange(long value) const -> bool;
            [[nodiscard]] auto constexpr start() const -> long { return _start; }
            [[nodiscard]] auto constexpr end() const -> long { return _end; }
        };

        class ParsedInput
        {
        private:
            std::vector<Range> _ranges;
            const std::vector<long> _ids;
            [[nodiscard]] static auto sortAndCombine(const std::vector<Range> &ranges) -> std::vector<Range>;

        public:
            ParsedInput(const std::vector<Range>& ranges, const std::vector<long>& ids)
                : _ranges{sortAndCombine(ranges)}, _ids{ids}
            {

            }


            [[nodiscard]] auto constexpr ids() const -> const std::vector<long>& { return _ids; }
            [[nodiscard]] auto constexpr ranges() const -> const std::vector<Range>& { return _ranges; };
        };

        [[nodiscard]] static auto parseRange(const std::string_view &range) -> Range;
        [[nodiscard]] static auto parseInput(const std::string_view &input) -> ParsedInput;
    };
}

#endif //AOC25_DAY_FIVE_H
