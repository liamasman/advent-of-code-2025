#include "../../include/days/day_two.h"

#include "utils/string_utils.h"

auto DayTwo::partOne(const std::string &input) const -> std::string
{
    long sum{0};
    for (const auto &idPairRange : splitCommas(input))
    {
        const auto [firstId, secondId]{getPair(std::string{idPairRange.begin(), idPairRange.end()}, '-')};
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

auto DayTwo::partTwo(const std::string &input) const -> std::string
{
    return "To be implemented";
}

auto DayTwo::isValidId(long id) -> bool

{
    std::string asString{std::to_string(id)};
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
