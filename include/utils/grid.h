#ifndef AOC25_GRID_H
#define AOC25_GRID_H
#include <array>
#include <cassert>
#include <string>
#include <vector>
#include <iostream>

template<typename T>
class Grid
{
private:
    std::vector<T> _data;
    int _width;
    int _height;

    constexpr auto isValidPosition(int x, int y) const -> bool
    {
        return x >= 0 && x < _width && y >= 0 && y < _height;
    }

    template<class CellPtr>
    constexpr auto collectNeighbours(int x, int y) const -> std::vector<CellPtr>
    {
        std::vector<CellPtr> neighbours{};
        for (const auto& [dx, dy] : DIRECTIONS)
        {
            const int neighbourX = x + dx;
            const int neighbourY = y + dy;
            if (isValidPosition(neighbourX, neighbourY))
            {
                neighbours.push_back(const_cast<Grid*>(this)->getCell(neighbourX, neighbourY));
            }
        }
        return neighbours;
    }

    constexpr auto coordinateIndex(int x, int y) const -> int
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
    constexpr Grid(const std::vector<T> &data, int width, int height)
        : _data{data}, _width{width}, _height{height}
    {
        validateDimensions(data.size(), width, height);
    }

    constexpr Grid(const std::string &data, int width, int height)
        : Grid(std::vector(data.begin(), data.end()), width, height)
    {
    }

    constexpr auto getCell(int x, int y) -> T
    {
        return _data[y * _width + x];
    }

    constexpr auto getCell(int x, int y) const -> const T
    {
        return _data[y * _width + x];
    }

    constexpr auto setCell(int x, int y, T value) -> void
    {
        _data[coordinateIndex(x, y)] = value;
    }

    constexpr auto getNeighbours(int x, int y) const -> std::vector<T>
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

    constexpr auto width() const -> int
    {
        return _width;
    }

    constexpr auto height() const -> int
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


#endif //AOC25_GRID_H
