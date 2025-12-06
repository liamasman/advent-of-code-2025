#include "days/day_six.h"

#include <cassert>
#include <iostream>

#include "utils/string_utils.h"

#include <vector>

namespace aoc25::days
{
    auto DaySix::partOne(const std::string &input) const -> std::string
    {
        auto lines {utils::getLines(input)};
        std::vector<std::vector<long>> longs;
        std::vector<char> operands;

        std::vector<std::string> linesVector;
        for (const auto &line : lines)
        {
            linesVector.emplace_back(line.begin(), line.end());
        }

        for (size_t i{0}; i < linesVector.size() - 1; ++i)
        {
            const auto words = utils::splitWhitespace(linesVector[i]);
            std::vector<long> lineLongs;
            for (const auto& word : words)
            {
                lineLongs.push_back(std::stol(word));
            }
            longs.push_back(lineLongs);
        }

        const std::string& operandsLines = linesVector.back();
        for (const auto chars{utils::splitWhitespace(operandsLines)}; const auto& character : chars)
        {
            assert(character.size() == 1);
            operands.push_back(character.front());
        }

#ifndef NDEBUG
        for (int i{0}; i < longs.size(); ++i)
        {
        assert(longs[0].size() == longs[i].size());
        }
        assert(longs[0].size() == operands.size());
#endif

        long total{0};
        for (int i{0}; i < longs[0].size(); ++i)
        {
            long result{longs[0][i]};
            for (int j{1}; j < longs.size(); ++j)
            {
                switch (operands[i])
                {
                    case '+': result += longs[j][i]; break;
                    case '*': result *= longs[j][i]; break;
                    default: throw std::runtime_error{"Invalid operand " + std::to_string(operands[i]) + " at position " + std::to_string(i)};
                }
            }
            total += result;
        }

        return std::to_string(total);
    }

    auto DaySix::partTwo(const std::string &input) const -> std::string
    {
        return "To be implemented.";
    }
}
