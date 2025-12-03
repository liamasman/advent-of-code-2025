#include <iostream>

void printUsage(const char* programName)
{
    std::cout << "Usage: " << programName << " day part [filename]\n";
}

int main(const int argc, const char *argv[])
{
    if (argc < 3)
    {
        printUsage(argv[0]);
        return 1;
    }

    const int day{std::stoi(argv[1])};
    if (day <= 0 || day > 12)
    {
        printUsage(argv[0]);
        return 1;
    }

    const int part{std::stoi(argv[2])};
    if (part <= 0 || part > 2)
    {
        printUsage(argv[0]);
        return 1;
    }


    const std::optional<std::string> input = (argc >= 4)
        ? std::optional{std::string{argv[3]}}
        : std::nullopt;

    std::cout << "Running day " << day << ", part " << part;
    if (input.has_value())
    {
        std::cout << " using input file '" << input.value() << "'";
    }
    std::cout << "\n";
}