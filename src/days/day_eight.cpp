#include "days/day_eight.h"

#include <assert.h>
#include <map>
#include <memory>
#include <set>

#include "utils/string_utils.h"

using namespace aoc25::days;

auto DayEight::partOne(const std::string &input) const -> std::string
{
    return partOne(input, 1000);
}


auto DayEight::partOne(
    const std::string &input,
    const int iterations) -> std::string
{
    auto lines = utils::getLines(input);
    std::vector<day_eight::Vec3> points;
    for (const auto &line : lines)
    {
        points.emplace_back(parseVec3(line.data()));
    }

    // Get the distance from all points to all other points
    // Store in a TreeSet sorted by smallest distance
    std::set<day_eight::PointPairDistance, decltype(day_eight::PointPairDistance::getKeyComparator())> distances(day_eight::PointPairDistance::getKeyComparator());

    for (const auto &a : points)
    {
        for (const auto &b : points)
        {
            if (a == b || !(a < b))
            {
                continue;
            }

            distances.emplace(a, b);
        }
    }

    std::map<day_eight::Vec3, std::shared_ptr<day_eight::Circuit>> pointToCircuit;
    auto circuitComparator = [](const std::shared_ptr<day_eight::Circuit>& a, const std::shared_ptr<day_eight::Circuit>& b) {
        if (a->size() > b->size())
        {
            return true;
        }
        if (b -> size() > a->size())
        {
            return false;
        }
        return *(a->_junctionBoxes.begin()) < *(b->_junctionBoxes.begin());
    };
    std::set<std::shared_ptr<day_eight::Circuit>, decltype(circuitComparator)> circuits(circuitComparator);


    for (size_t pairs_made{0}; pairs_made < iterations; ++pairs_made)
    {
        const auto distance = distances.begin();

        auto circuitA = pointToCircuit.find(distance->_pointA);
        auto circuitB = pointToCircuit.find(distance->_pointB);

        if (circuitA == pointToCircuit.end() && circuitB == pointToCircuit.end())
        {
            // Construct a new circuit
            std::set<day_eight::Vec3> circuitBoxes;
            circuitBoxes.emplace(distance->_pointA);
            circuitBoxes.emplace(distance->_pointB);

            auto circuit = std::make_shared<day_eight::Circuit>(circuitBoxes);

            pointToCircuit.emplace(distance->_pointA, circuit);
            pointToCircuit.emplace(distance->_pointB, circuit);
            circuits.emplace(circuit);
        }
        else if (circuitB == pointToCircuit.end())
        {
            // Add point to circuit a
            circuits.erase(circuitA->second);
            circuitA->second->_junctionBoxes.emplace(distance->_pointB);
            circuits.emplace(circuitA->second);
            pointToCircuit.emplace(distance->_pointB, circuitA ->second);
        }
        else if (circuitA == pointToCircuit.end())
        {
            // Add point to circuit B
            circuits.erase(circuitB->second);
            circuitB->second->_junctionBoxes.emplace(distance->_pointA);
            circuits.emplace(circuitB->second);
            pointToCircuit.emplace(distance->_pointA, circuitB ->second);
        }
        else if (circuitA->second != circuitB->second)
        {
            // Combine Circuit
            const auto circuitBJunctionBoxes = circuitB->second->_junctionBoxes;

            circuits.erase(circuitA->second);
            circuits.erase(circuitB->second);
            std::set<day_eight::Vec3> merged;
            merged.insert(circuitA->second->_junctionBoxes.begin(), circuitA->second->_junctionBoxes.end());
            merged.insert(circuitB->second->_junctionBoxes.begin(), circuitB->second->_junctionBoxes.end());
            circuitA->second->_junctionBoxes = merged;
            circuits.emplace(circuitA->second);
            for (auto& junctionBox : circuitBJunctionBoxes)
            {
                pointToCircuit[junctionBox] = circuitA->second;
            }
        }
        else
        {
            // else points already in same circuit - do nothing
            assert(circuitA->second == circuitB->second);
            assert(circuitA->second->_junctionBoxes.contains(distance->_pointA));
            assert(circuitA->second->_junctionBoxes.contains(distance->_pointB));
            assert(circuitB->second->_junctionBoxes.contains(distance->_pointA));
            assert(circuitB->second->_junctionBoxes.contains(distance->_pointB));
        }

        distances.erase(distance);
    }


    long multiplication = {1};
    for (size_t i{0}; i < 3; ++i)
    {
        multiplication *= static_cast<long>((*circuits.begin())->size());
        circuits.erase(circuits.begin());
    }

    return std::to_string(multiplication);
}

auto DayEight::partTwo(
    const std::string &input) const -> std::string
{
        auto lines = utils::getLines(input);

    auto circuitComparator = [](const std::shared_ptr<day_eight::Circuit>& a, const std::shared_ptr<day_eight::Circuit>& b) {
        if (a->size() > b->size())
        {
            return true;
        }
        if (b -> size() > a->size())
        {
            return false;
        }
        return *(a->_junctionBoxes.begin()) < *(b->_junctionBoxes.begin());
    };
    std::set<std::shared_ptr<day_eight::Circuit>, decltype(circuitComparator)> circuits(circuitComparator);
    std::map<day_eight::Vec3, std::shared_ptr<day_eight::Circuit>> pointToCircuit;

    std::vector<day_eight::Vec3> points;
    for (const auto &line : lines)
    {
        auto point{parseVec3(line.data())};
        points.push_back(point);

        std::shared_ptr circuit{std::make_shared<day_eight::Circuit>()};

        circuit->_junctionBoxes.emplace(points.back());
        circuits.emplace(circuit);
        pointToCircuit.emplace(point, circuit);
    }

    // Get the distance from all points to all other points
    // Store in a TreeSet sorted by smallest distance
    std::set<day_eight::PointPairDistance, decltype(day_eight::PointPairDistance::getKeyComparator())> distances(day_eight::PointPairDistance::getKeyComparator());

    for (const auto &a : points)
    {
        for (const auto &b : points)
        {
            if (a == b || !(a < b))
            {
                continue;
            }

            distances.emplace(a, b);
        }
    }

    std::optional<day_eight::PointPairDistance> lastDistance;
    while (circuits.size() > 1)
    {
        auto distance = distances.begin();

        auto circuitA = pointToCircuit.find(distance->_pointA);
        auto circuitB = pointToCircuit.find(distance->_pointB);

        if (circuitA == pointToCircuit.end() && circuitB == pointToCircuit.end())
        {
            // Construct a new circuit
            std::set<day_eight::Vec3> circuitBoxes;
            circuitBoxes.emplace(distance->_pointA);
            circuitBoxes.emplace(distance->_pointB);

            auto circuit = std::make_shared<day_eight::Circuit>(circuitBoxes);

            pointToCircuit.emplace(distance->_pointA, circuit);
            pointToCircuit.emplace(distance->_pointB, circuit);
            circuits.emplace(circuit);
        }
        else if (circuitB == pointToCircuit.end())
        {
            // Add point to circuit a
            circuits.erase(circuitA->second);
            circuitA->second->_junctionBoxes.emplace(distance->_pointB);
            circuits.emplace(circuitA->second);
            pointToCircuit.emplace(distance->_pointB, circuitA ->second);
        }
        else if (circuitA == pointToCircuit.end())
        {
            // Add point to circuit B
            circuits.erase(circuitB->second);
            circuitB->second->_junctionBoxes.emplace(distance->_pointA);
            circuits.emplace(circuitB->second);
            pointToCircuit.emplace(distance->_pointA, circuitB ->second);
        }
        else if (circuitA->second != circuitB->second)
        {
            // Combine Circuit
            const auto circuitBJunctionBoxes = circuitB->second->_junctionBoxes;

            circuits.erase(circuitA->second);
            circuits.erase(circuitB->second);
            std::set<day_eight::Vec3> merged;
            merged.insert(circuitA->second->_junctionBoxes.begin(), circuitA->second->_junctionBoxes.end());
            merged.insert(circuitB->second->_junctionBoxes.begin(), circuitB->second->_junctionBoxes.end());
            circuitA->second->_junctionBoxes = merged;
            circuits.emplace(circuitA->second);
            for (auto& junctionBox : circuitBJunctionBoxes)
            {
                pointToCircuit[junctionBox] = circuitA->second;
            }
        }
        else
        {
            // else points already in same circuit - do nothing
            assert(circuitA->second == circuitB->second);
            assert(circuitA->second->_junctionBoxes.contains(distance->_pointA));
            assert(circuitA->second->_junctionBoxes.contains(distance->_pointB));
            assert(circuitB->second->_junctionBoxes.contains(distance->_pointA));
            assert(circuitB->second->_junctionBoxes.contains(distance->_pointB));
        }

        lastDistance.emplace(*distance);
        distances.erase(distance);
    }

    return std::to_string(lastDistance->_pointA._x * lastDistance->_pointB._x);
}

day_eight::Vec3 DayEight::parseVec3(const std::string_view &input)
{
    auto split = utils::splitCommas(input);
    auto it = split.begin();

    const int x = std::stoi(std::string((*it).begin(), (*it).end()));
    ++it;
    const int y = std::stoi(std::string((*it).begin(), (*it).end()));
    ++it;
    const int z = std::stoi(std::string((*it).begin(), (*it).end()));

    return day_eight::Vec3{x, y, z};
}