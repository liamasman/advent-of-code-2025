#include "days/day_nine.h"

#include "utils/string_utils.h"

#include <iostream>
#include <map>
#include <set>
#include <stack>

#include "utils/grid.h"

namespace aoc25::days
{
    using namespace daynine;

    auto DayNine::getPointsList(
        const std::string &input) -> std::vector<std::pair<size_t, size_t>>
    {
        std::vector<std::pair<size_t, size_t> > points;
        for (const auto &line: utils::getLines(input))
        {
            const auto &[xString, yString] = utils::getPair(
                {line.begin(), line.end()}, ',');
            const size_t x = std::stoi(xString);
            const size_t y = std::stoi(yString);
            points.emplace_back(x, y);
        }

        return points;
    }

    auto DayNine::partOne(const std::string &input) const -> std::string
    {
        const auto points{getPointsList(input)};

        long maxArea{0};

        for (size_t i{0}; i < points.size(); ++i)
        {
            const auto [x1, y1] = points[i];
            for (size_t j{i + 1}; j < points.size(); ++j)
            {
                const auto [x2, y2] = points[j];

                long area{std::abs(static_cast<long>(x1 - x2 + 1)) * std::abs(static_cast<long>(y1 - y2 + 1))};
                if (area > maxArea)
                {
                    maxArea = area;
                }
            }
        }

        return std::to_string(maxArea);
    }

    auto DayNine::partTwo(const std::string &input) const -> std::string
    {
        const auto points{getPointsList(input)};
        const auto compressedPoints{compressCoordinates(points)};

        const auto& grid{computeGrid(compressedPoints)};

        printGrid(grid);

        long maxArea{0};
        for (size_t i{0}; i < compressedPoints.size(); ++i)
        {
            for (size_t j{i + 1}; j < compressedPoints.size(); ++j)
            {
                const auto &compressedPointA = compressedPoints[i];
                const auto &compressedPointB = compressedPoints[j];
                if (safeRectangle(compressedPointA, compressedPointB, grid))
                {
                    const auto &pointA = points[i];
                    const auto &pointB = points[j];

                    long area{std::abs(static_cast<long>(pointA.first - pointB.first + 1)) *
                        std::abs(static_cast<long>(pointA.second - pointB.second + 1))};
                    if (area > maxArea)
                    {
                        maxArea = area;
                    }
                }
            }
        }

        return std::to_string(maxArea);
    }

    auto DayNine::compressCoordinates(
        const std::vector<std::pair<size_t, size_t> > &points) -> std::vector<
        std
        ::pair<size_t, size_t> >
    {
        std::set<size_t> x_coords;
        std::set<size_t> y_coords;
        for (const auto& [x, y] : points)
        {
            x_coords.insert(x);
            y_coords.insert(y);
        }

        std::map<size_t, size_t> x_map;
        std::map<size_t, size_t> y_map;

        for (int i{1}; !x_coords.empty(); i += 2) //Give a gap between each coordinate and a border on the left
        {
            const size_t originalX = *x_coords.begin();
            x_coords.erase(x_coords.begin());
            x_map[originalX] = i;
        }
        for (int i{1}; !y_coords.empty(); i += 2) //Give a gap between each coordinate and a border on the top
        {
            const size_t originalY = *y_coords.begin();
            y_coords.erase(y_coords.begin());
            y_map[originalY] = i;
        }

        std::vector<std::pair<size_t, size_t>> compressedPoints;
        compressedPoints.reserve(points.size());
        for (const auto& [x, y] : points)
        {
            size_t new_x = x_map[x];
            size_t new_y = y_map[y];
            compressedPoints.emplace_back(new_x, new_y);
        }
        return compressedPoints;
    }

    void DayNine::floodFill(utils::Grid<Cell> &grid)
    {
        utils::Grid visited(false, grid.width(), grid.height());
        std::stack<std::pair<size_t, size_t>> toVisit{};
        toVisit.emplace(0, 0); // Guaranteed to be empty

        while (!toVisit.empty())
        {
            const auto [x, y] = toVisit.top();
            toVisit.pop();

            for (const auto& neighbour_coordinate : grid.getCardinalNeighbourCoordinates(x, y))
            {
                const auto [neighbour_x, neighbour_y] = neighbour_coordinate;
                if (grid.getCell(neighbour_x, neighbour_y) == EMPTY &&
                    !visited.getCell(neighbour_x, neighbour_y))
                {
                    visited.setCell(neighbour_x, neighbour_y, true);
                    toVisit.emplace(neighbour_x, neighbour_y);
                }
            }
        }

        for (size_t x{0}; x < grid.width(); ++x)
        {
            for (size_t y{0}; y < grid.height(); ++y)
            {
                if (!visited.getCell(x, y))
                {
                    grid.setCell(x, y, TILE);
                }
            }
        }
    }

    void inline DayNine::createOutline(const std::vector<std::pair<size_t, size_t>> &redTiles, utils::Grid<Cell> &grid)
    {
        auto [last_x, last_y]{redTiles.back()};
        for (size_t i{0}; i < redTiles.size(); ++i)
        {
            const auto [x, y] = redTiles[i];
            grid.setCell(x, y, TILE);
            if (x == last_x)
            {
                for (size_t dy{std::min(y, last_y) + 1}; dy < std::max(y, last_y); ++dy)
                {
                    grid.setCell(x, dy, TILE);
                }
            }
            else
            {
                for (size_t dx{std::min(x, last_x) + 1}; dx < std::max(x, last_x); ++dx)
                {
                    grid.setCell(dx, y, TILE);
                }
            }
            last_x = x;
            last_y = y;
        }
    }

    auto DayNine::computeGrid(
        const std::vector<std::pair<size_t, size_t>> &redTiles) -> utils::Grid<Cell>
    {
        size_t max_x{0};
        size_t max_y{0};
        for (const auto& [x, y] : redTiles)
        {
            max_x = std::max(max_x, x);
            max_y = std::max(max_y, y);
        }
        utils::Grid grid{std::vector((max_x + 2) * (max_y + 2), EMPTY), max_x + 2, max_y + 2};

        createOutline(redTiles, grid);
        floodFill(grid);

        return grid;
    }

    auto inline DayNine::safeRectangle(const std::pair<size_t, size_t> &pointA,
        const std::pair<size_t, size_t> &pointB,
        const utils::Grid<Cell> &grid) -> bool
    {
        const auto& [x1, y1] = pointA;
        const auto& [x2, y2] = pointB;

        for (size_t x{std::min(x1, x2)}; x <= std::max(x1, x2); ++x)
        {
            for (size_t y{std::min(y1, y2)}; y <= std::max(y1, y2); ++y)
            {
                if (grid.getCell(x, y) == EMPTY)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void DayNine::printGrid(const utils::Grid<Cell> &grid)
    {
        for (size_t y{0}; y < grid.height(); ++y)
        {
            for (size_t x{0}; x < grid.width(); ++x)
            {
                std::cout << (grid.getCell(x, y) ? '#' : '.');
            }
            std::cout << '\n';
        }
    }
}
