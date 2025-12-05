#ifndef AOC25_STRING_UTILS_H
#define AOC25_STRING_UTILS_H
#include <fstream>
#include <ranges>
#include <sstream>
#include <string>

namespace aoc25::utils
{
    inline auto getLines(const std::string &input)
    {
        return std::views::split(input, '\n');
    }

    inline auto splitCommas(const std::string &input)
    {
        return std::views::split(input, ',');
    }

    inline auto getPair(const std::string_view input, const char delimiter)
    {
        //TODO exception if can not find delimiter
        const auto index = input.find(delimiter);
        return std::make_pair(
            std::string{input.substr(0, index)},
            std::string{input.substr(index + 1)}
        );
    }

    inline auto readFile(const std::string &filename) -> std::string
    {
        //TODO exception if file does not exist
        std::ifstream inputFile{filename};
        const auto contents = std::string{
            (std::istreambuf_iterator(inputFile)), std::istreambuf_iterator<char>()
        };
        inputFile.close();
        return contents;
    }

    inline auto repeat(const std::string &str, const int n) -> std::string
    {
        std::ostringstream os;
        for(int i{0}; i < n; i++)
        {
            os << str;
        }
        return os.str();
    }
}
#endif //AOC25_STRING_UTILS_H