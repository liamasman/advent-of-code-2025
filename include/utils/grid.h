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
        int _width;
        int _height;

        [[nodiscard]] constexpr auto isValidPosition(const int x, const int y) const -> bool
        {
            return x >= 0 && x < _width && y >= 0 && y < _height;
        }

        [[nodiscard]] constexpr auto coordinateIndex(const int x, const int y) const -> int
        {
            return y * _width + x;
        }

        static constexpr std::array<std::pair<int, int>, 8> DIRECTIONS = {{{-1, 0},
                                                                {-1, -1},
                                                                {0, -1},
                                                                {1, -1},
                                                                {1, 0},
                                                                {1, 1},
                                                                {0, 1},
                                                                {-1, 1}}};

        static constexpr auto validateDimensions(size_t dataSize, int width, int height) -> void
        {
            assert(dataSize == static_cast<size_t>(width) * height);
        }
    public:
        constexpr Grid(const std::vector<T> data, const int width, const int height)
            : _data{data}, _width{width}, _height{height}
        {
            validateDimensions(data.size(), width, height);
        }

        constexpr Grid(const std::string &data, int width, int height)
            : Grid(std::vector(data.begin(), data.end()), width, height)
        {
        }

        [[nodiscard]] constexpr auto getCell(const int x, const int y) -> T
        {
            return _data[y * _width + x];
        }

        [[nodiscard]] constexpr auto getCell(const int x, const int y) const -> T
        {
            return _data[y * _width + x];
        }

        constexpr auto setCell(const int x, const int y, T value) -> void
        {
            _data[coordinateIndex(x, y)] = value;
        }

        [[nodiscard]] constexpr auto getNeighbours(const int x, const int y) const -> std::vector<T>
        {
            std::vector<char> neighbours{};
            for (const auto& [dx, dy] : DIRECTIONS)
            {
                const int neighbourX = x + dx;
                const int neighbourY = y + dy;
                if (isValidPosition(neighbourX, neighbourY))
                {
                    neighbours.push_back(getCell(neighbourX, neighbourY));
                }
            }
            return neighbours;
        }

        [[nodiscard]] constexpr auto width() const -> int
        {
            return _width;
        }

        [[nodiscard]] constexpr auto height() const -> int
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
            for (int y{0}; y < grid._height; y++)
            {
                for (int x{0}; x < grid._width; x++)
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
