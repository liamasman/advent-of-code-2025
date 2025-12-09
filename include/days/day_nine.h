#ifndef AOC25_DAY_NINE_H
#define AOC25_DAY_NINE_H
#include <iostream>
#include <set>
#include <vector>

#include "abstract_day.h"
#include "utils/grid.h"

namespace aoc25::days
{
    namespace daynine
    {
        typedef bool Cell;
        static constexpr Cell EMPTY{false};
        static constexpr Cell TILE{true};
    }

    class DayNine : public AbstractDay
    {
    public:
        [[nodiscard]] auto partOne(
            const std::string &input) const -> std::string override;

        [[nodiscard]] auto partTwo(
            const std::string &input) const -> std::string override;

    private:
        [[nodiscard]] static auto getPointsList(
            const std::string &input) -> std::vector<std::pair<size_t, size_t>>;

        [[nodiscard]] static auto computeGrid(const std::vector<std::pair<size_t, size_t>> & redTiles) -> utils::Grid<daynine::Cell>;

        [[nodiscard]] static auto compressCoordinates(const std::vector<std::pair<size_t, size_t>> &points) -> std::vector<std::pair<size_t, size_t>>;

        static inline void createOutline(
            const std::vector<std::pair<size_t, size_t>> &redTiles,
            utils::Grid<daynine::Cell> &grid);

        static inline void floodFill(
            utils::Grid<daynine::Cell> &grid);

        static inline auto safeRectangle(const std::pair<size_t, size_t> & pointA,
                                         const std::pair<size_t, size_t> & pointB,
                                         const utils::Grid<daynine::Cell> & grid) -> bool;

        static void printGrid(const utils::Grid<daynine::Cell> & grid);
    };
}

#endif //AOC25_DAY_NINE_H
