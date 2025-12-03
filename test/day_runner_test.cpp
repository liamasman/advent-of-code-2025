#include "day_runner.h"

#include <fstream>
#include <gtest/gtest.h>

class StubDay: public AbstractDay
{
    [[nodiscard]] std::string partOne(const std::string& input) const override
    {
        return "Part One - " + input;
    }

    [[nodiscard]] std::string partTwo(const std::string& input) const override
    {
        return "Part Two - " + input;
    }
};

TEST(DayRunnerTest, PassesFileContentsToPartOne) {
    const std::string data{"This is some data."};
    const std::string filename{"/tmp/test_file.txt"};
    std::ofstream file = std::ofstream{filename};
    file << data;
    file.close();

    const auto result = DayRunner::run(StubDay{}, 1, filename);
    EXPECT_EQ(result, "Part One - This is some data.");
}

TEST(DayRunnerTest, PassesFileContentsToPartTwo) {
    const std::string data{"This is some data."};
    const std::string filename{"/tmp/test_file.txt"};
    std::ofstream file = std::ofstream{filename};
    file << data;
    file.close();

    const auto result = DayRunner::run(StubDay{}, 2, filename);
    EXPECT_EQ(result, "Part Two - This is some data.");
}