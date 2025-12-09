#ifndef AOC25_GRID_H
#define AOC25_GRID_H
#include <array>
#include <cassert>
#include <string>
#include <vector>
#include <iostream>

namespace aoc25::utils
{
    template<typename T>
    class Grid
    {
    private:
        std::vector<T> _data;
        size_t _width;
        size_t _height;

        [[nodiscard]] constexpr auto isValidPosition(const size_t x, const size_t y) const -> bool
        {
            return x < _width && y < _height;
        }

        [[nodiscard]] constexpr auto coordinateIndex(const size_t x, const size_t y) const -> size_t
        {
            return y * _width + x;
        }

        static constexpr std::array<std::pair<int, int>, 8> DIRECTIONS{{{-1, 0},
                                                                {-1, -1},
                                                                {0, -1},
                                                                {1, -1},
                                                                {1, 0},
                                                                {1, 1},
                                                                {0, 1},
                                                                {-1, 1}}};
        static constexpr std::array<std::pair<int, int>, 4> CARDINAL_DIRECTIONS{{{-1, 0},
                                                                {0, -1},
                                                                {1, 0},
                                                                {0, 1}}};

        static constexpr auto validateDimensions(const size_t dataSize, const size_t width, const size_t height) -> void
        {
            assert(dataSize == static_cast<size_t>(width) * height);
        }

    public:
        constexpr Grid(const std::vector<T> data, const size_t width, const size_t height)
            : _data{data}, _width{width}, _height{height}
        {
            validateDimensions(data.size(), width, height);
        }

        constexpr Grid(const std::string &data, const size_t width, const size_t height)
            : Grid(std::vector(data.begin(), data.end()), width, height)
        {
        }

        constexpr Grid(const T initialValue, const size_t width, const size_t height)
            : Grid(std::vector<T>(width * height, initialValue), width, height)
        {
        }

        [[nodiscard]] constexpr auto getCell(const size_t x, const size_t y) -> T
        {
            return _data[y * _width + x];
        }

        [[nodiscard]] constexpr auto getCell(const size_t x, const size_t y) const -> T
        {
            return _data[y * _width + x];
        }

        constexpr auto setCell(const size_t x, const size_t y, T value) -> void
        {
            _data[coordinateIndex(x, y)] = value;
        }

        [[nodiscard]] constexpr auto getNeighbours(const size_t x, const size_t y) const -> std::vector<T>
        {
            std::vector<T> neighbours{};
            for (const auto& [dx, dy] : DIRECTIONS)
            {
                const size_t neighbourX = x + dx;
                const size_t neighbourY = y + dy;
                if (isValidPosition(neighbourX, neighbourY))
                {
                    neighbours.push_back(getCell(neighbourX, neighbourY));
                }
            }
            return neighbours;
        }

        [[nodiscard]] constexpr auto getCardinalNeighbourCoordinates(const size_t x, const size_t y) const -> std::vector<std::pair<size_t, size_t>>
        {
            std::vector<std::pair<size_t, size_t>> neighbours{};
            for (const auto& [dx, dy] : CARDINAL_DIRECTIONS)
            {
                const size_t neighbourX = x + dx;
                const size_t neighbourY = y + dy;
                if (isValidPosition(neighbourX, neighbourY))
                {
                    neighbours.emplace_back(neighbourX, neighbourY);
                }
            }
            return neighbours;
        }

        [[nodiscard]] constexpr auto width() const -> size_t
        {
            return _width;
        }

        [[nodiscard]] constexpr auto height() const -> size_t
        {
            return _height;
        }

        friend constexpr auto operator==(const Grid &lhs, const Grid &rhs) -> bool
        {
            return lhs._width == rhs._width &&
                   lhs._height == rhs._height &&
                   lhs._data == rhs._data;
        }

        friend std::ostream & operator<<(std::ostream &stream, const Grid &grid) {
            for (size_t y{0}; y < grid._height; y++)
            {
                for (size_t x{0}; x < grid._width; x++)
                {
                    stream << grid.getCell(x, y);
                    if (x < grid._width - 1)
                    {
                        stream << ", ";
                    }
                }
                if (y < grid._height - 1)
                {
                    stream << "\n";
                }
            }
            return stream;
        }

    };
}
#endif //AOC25_GRID_H
