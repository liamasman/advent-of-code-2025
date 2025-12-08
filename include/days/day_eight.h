#ifndef AOC25_DAY_EIGHT_H
#define AOC25_DAY_EIGHT_H
#include <numeric>
#include <set>
#include <cmath>

#include "abstract_day.h"

namespace aoc25::days
{
    namespace day_eight
    {
        class Vec3
        {
        public:
            const int _x;
            const int _y;
            const int _z;

            Vec3(const int x, const int y, const int z) :
                _x{x}, _y{y}, _z{z}
            {};

            [[nodiscard]] long squareDistanceTo(const Vec3& other) const
            {
                const long _delta_x = std::abs(_x - other._x);
                const long _delta_y = std::abs(_y - other._y);
                const long _delta_z = std::abs(_z - other._z);
                return _delta_x * _delta_x +
                    _delta_y * _delta_y +
                    _delta_z * _delta_z;
            }

            bool operator==(const Vec3 & other) const
            {
                return this->_x == other._x &&
                    this->_y == other._y &&
                    this->_z == other._z;
            }

            bool operator<(const Vec3 &other) const
            {
                if (this-> _x < other._x)
                {
                    return true;
                }
                else if (this->_x > other._x)
                {
                    return false;
                }
                else if (this -> _y < other._y)
                {
                    return true;
                }
                else if (this->_y > other._y)
                {
                    return false;
                }
                else
                {
                    return this->_z < other._z;
                }
            }
        };

        class PointPairDistance
        {
        public:
            const Vec3 _pointA;
            const Vec3 _pointB;
            const long _squareDistance;

            PointPairDistance(const Vec3& pointA, const Vec3& pointB) :
                _pointA{pointA},
                _pointB{pointB},
                _squareDistance{pointA.squareDistanceTo(pointB)}
            {};

            [[nodiscard]] static auto getKeyComparator()
            {
                return [](const PointPairDistance &a, const PointPairDistance &b)
                {
                    if (a._squareDistance < b._squareDistance)
                    {
                        return true;
                    }
                    else if (b._squareDistance < a._squareDistance)
                    {
                        return false;
                    }
                    else if (a._pointA < b._pointA)
                    {
                        return true;
                    }
                    else if (b._pointA < a._pointA)
                    {
                        return false;
                    }
                    else if (a._pointB < b._pointB)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                };
            }

            [[nodiscard]] bool operator<(const PointPairDistance &other) const
            {
                return _squareDistance < other._squareDistance;
            }
        };

        class Circuit
        {
        public:
            std::set<Vec3> _junctionBoxes;

            [[nodiscard]] auto size() const -> size_t
            {
                return _junctionBoxes.size();
            }
        };
    }

    class DayEight : public AbstractDay
    {
    public:
        [[nodiscard]] auto partOne(const std::string &input) const -> std::string override;
        [[nodiscard]] static auto partOne(const std::string &input, int iterations) -> std::string;
        [[nodiscard]] auto partTwo(const std::string &input) const -> std::string override;
    private:
        static day_eight::Vec3 parseVec3(const std::string_view &input);
    };
}
#endif //AOC25_DAY_EIGHT_H
