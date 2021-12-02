#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("readings.txt");

    int prev = 9999999, total = 0;
    for (std::string line; std::getline(file, line);)
    {
        int depth = std::stoi(line);
        total += depth > prev;
        prev = depth;
    }

    std::cout << "Number of increases: " << total << "\n";
    return 0;
}