#include "days/day_two.h"
#include "utils/string_utils.h"

namespace aoc25::days
{
    auto DayTwo::partOne(const std::string &input) const -> std::string
    {
        return runAnalysis(input, &DayTwo::isValidIdPartOne);
    }

    auto DayTwo::partTwo(const std::string &input) const -> std::string
    {
        return runAnalysis(input, &DayTwo::isValidIdPartTwo);
    }

    auto DayTwo::runAnalysis(const std::string &input, const auto isValidId) -> std::string
    {
        long sum{0};
        for (const auto &idPairRange : utils::splitCommas(input))
        {
            const auto [firstId, secondId]{utils::getPair({idPairRange.begin(), idPairRange.end()}, '-')};
            auto id{std::stol(firstId)};
            const auto secondIdInt{std::stol(secondId)};

            while (id <= secondIdInt)
            {
                if (!isValidId(id))
                {
                    sum += id;
                }
                ++id;
            }
        }
        return std::to_string(sum);
    }

    auto DayTwo::isValidIdPartOne(const long id) -> bool

    {
        const std::string asString{std::to_string(id)};
        if (asString.size() % 2 != 0)
        {
            return true;
        }

        const auto halfLength = asString.size() / 2;
        int i{0};
        while (i < halfLength)
        {
            if (asString[i] != asString[i + halfLength])
            {
                return true;
            }
            ++i;
        }
        return false;
    }

    auto DayTwo::isValidIdPartTwo(const long id) -> bool
    {
        const std::string asString{std::to_string(id)};
        for (int i{1}; i <= asString.size() / 2; ++i)
        {
            if (asString.size() % i != 0)
            {
                continue;
            }
            const auto substring = asString.substr(0, i);
            if (const auto repeated = utils::repeat(substring, asString.size() / i); repeated == asString)
            {
                return false;
            }
        }
        return true;
    }
}